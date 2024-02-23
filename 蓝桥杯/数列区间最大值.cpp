#include <limits>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

struct Node
{
	int l, r, maxv;
} tr[N];

int n, m, x, y;
int w[N];

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, w[l]};
	else
	{
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		tr[u].maxv = max(tr[u << 1].maxv, tr[u << 1 | 1].maxv);
	}
}

int query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].maxv;
	int mid = tr[u].l + tr[u].r >> 1;
	int maxv = INT_MIN;
	if (l <= mid) maxv = max(maxv, query(u << 1, l, r));
	if (r > mid) maxv = max(maxv, query(u << 1 | 1, l, r));
	return maxv;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	
	build(1, 1, n);
	
	while (m--)
	{
		scanf("%d%d", &x, &y);
		
		printf("%d\n", query(1, x, y));
	}
	
	return 0;
}
