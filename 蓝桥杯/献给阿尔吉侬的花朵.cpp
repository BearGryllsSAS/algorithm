#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

#define x first
#define y second

const int N = 210;

typedef pair<int, int> PII;

int T, n, m;
char g[N][N];
int dist[N][N];

int bfs(PII start, PII end)
{
	memset(dist, -1, sizeof dist);
	dist[start.x][start.y] = 0;
	
	queue<PII> q;
	q.push(start);
	
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (g[x][y] == '#') continue;
			if (dist[x][y] != -1) continue;
			
			dist[x][y] = dist[t.x][t.y] + 1;
			
			if (end == make_pair(x, y)) return dist[x][y];
			
			q.push({x, y});
		}
	}
	
	return -1;
}

int main()
{
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d%d", &n, &m);
		
		for (int i = 0; i < n; i++) scanf("%s", g[i]);
		
		PII start, end;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g[i][j] == 'S') start = {i, j};
				else if (g[i][j] == 'E') end = {i, j};
			}
		}
		
		int distance = bfs(start, end);
		if (distance == -1) puts("opp!");
		else printf("%d\n", distance);
	}
	
	return 0;
}
