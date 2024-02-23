#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m, k, a, b;
int arr[N];
int atr[N];

int lowbit(int x)
{
	return x & (-x);
}

void add(int index, int x)
{
	for (int i = index; i <= n; i += lowbit(i)) atr[i] += x;
}

int query(int index)
{
	int res = 0;
	for (int i = index; i > 0; i -= lowbit(i)) res += atr[i];
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	
	for (int i = 1; i <= n; i++) add(i, arr[i]);
	
	while (m--)
	{
		scanf("%d%d%d", &k, &a, &b);
		
		if (k == 0) printf("%d\n", query(b) - query(a - 1));
		else add(a, b);
	}
	
	return 0;
}
