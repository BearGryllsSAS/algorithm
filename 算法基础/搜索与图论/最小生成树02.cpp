#include <algorithm>
#include <iostream>
using namespace std;

/* 克鲁斯卡尔算法模板 */

const int N = 510, M = 2 * 1e5 + 10;

struct Edge
{
	int a, b, w;
	
	bool operator < (const Edge& W) const
	{
		return w < W.w;
	}
} edges[M];

int n, m, u, v, w;
int p[N];

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	
	return p[x];
}


int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		
		edges[i] = {u, v, w};
	}
	
	sort(edges, edges + m);
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	int res = 0, cnt = 0;
	
	for (int i = 0; i < m; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = find(a), b = find(b);
		
		if (a != b)
		{
			p[a] = b;
			
			res += w, cnt++;
		}
	}
	
	if (cnt != n - 1) puts("impossible");
	else cout << res << endl;
	
	return 0;
}
