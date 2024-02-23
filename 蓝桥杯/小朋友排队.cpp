#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

typedef long long LL;

int n;
int h[N], tr[N];
int sum[N];

int lowbit(int x)
{
	return x & -x;
}

void add(int u, int v)
{
	for (int i = u; i < N; i += lowbit(i)) tr[i] += v;
}

int query(int u)
{
	int res = 0;
	for (int i = u; i > 0; i -= lowbit(i)) res += tr[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	
	// 找到每一个数前面有多少个比它大 
	for (int i = 0; i < n; i++)
	{
		sum[i] += query(N - 1) - query(h[i]);
		add(h[i], 1);
	}

	memset(tr, 0, sizeof tr);

	// 找到每一个数后面有多少个比它小 
	for (int i = n - 1; i >= 0; i--)
	{
		sum[i] += query(h[i] - 1);
		add(h[i], 1);
	}
	
	LL res = 0;
	
	for (int i = 0; i < n; i++) res += (LL)sum[i] * (sum[i] + 1) / 2;
	
	cout << res << endl;
	
	return 0;
}
