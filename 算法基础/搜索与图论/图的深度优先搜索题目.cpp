#include <cstring>
#include <iostream>
using namespace std;

/* 图的深度优先遍历模板（树的重心）*/
// 邻接表才存储

const int N = 1e5 + 10, M = 2 * N;

int n, a, b;
int h[N], e[M], ne[M], idx;
int visit[N];
int res = N;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
	visit[u] = 1;
	
	int sum = 1, size = 0;
	
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		
		if (visit[j]) continue;
		
		int s = dfs(j);
		
		size = max(size, s);
		
		sum += s;
	}
	
	res = min(res, max(size, n - sum));
	
	return sum;
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n;
	
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &a, &b);
		
		add(a, b); add(b, a);
	}
	
	dfs(1);
	
	cout << res << endl;
	
	return 0;
}
