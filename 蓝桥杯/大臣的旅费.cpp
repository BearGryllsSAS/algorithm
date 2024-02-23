#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

struct Edge
{
	int id, w;
};

int n;
vector<Edge> h[N];
int w[N];

void dfs(int u, int father, int distance)
{
	w[u] = distance;
	
	for (const auto& node : h[u])
	{
		if (node.id != father)
		{
			dfs(node.id, u, distance + node.w);
		}
	}
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		h[a].push_back({b, c});
		h[b].push_back({a, c});
	}
	
	dfs(1, -1, 0);
	
	int u = 1;
	for (int i = 1; i <= n; i++) 
	{
		if (w[i] > w[u]) u = i;
	}
	
	dfs(u, -1, 0);
	
	u = 1;
	for (int i = 1; i <= n; i++)
	{
		if (w[i] > w[u]) u = i;
	}
	
	int s = w[u];
	
	printf("%lld\n", s * 10 + s * (s + 1ll) / 2);
	
	return 0;
}
