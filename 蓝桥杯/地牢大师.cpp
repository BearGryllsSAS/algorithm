#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 110;

struct Point
{
	int x, y, z;
};

int L, R, C;
char g[N][N][N];
int dist[N][N][N];
Point p[N * N * N];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs(Point start, Point end)
{
	memset(dist, -1, sizeof(dist));
	dist[start.x][start.y][start.z] = 0;
	
	int hh = 0, tt = -1;
	p[++tt] = start;
	
	while (hh <= tt)
	{
		auto t = p[hh++];
		
		for (int i = 0; i < 6; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i], z = t.z + dz[i];
			
			if (x < 0 || x >= L || y < 0 || y >= R || z < 0 || z >= C) continue;
			if (g[x][y][z] == '#') continue;
			if (dist[x][y][z] != -1) continue;
			
			dist[x][y][z] = dist[t.x][t.y][t.z] + 1;
			
			if (x == end.x && y == end.y && z == end.z) return dist[x][y][z];
			
			p[++tt] = {x, y, z};
		}
	}
	
	return -1;
}

int main()
{
	while (scanf("%d%d%d", &L, &R, &C), L || R || C)
	{
		Point start, end;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				scanf("%s", g[i][j]);
				
				for (int k = 0; k < C; k++)
				{
					if (g[i][j][k] == 'S') start = {i, j, k};
					if (g[i][j][k] == 'E') end = {i, j, k};
				}
			}
		}
		
		int ret = bfs(start, end);
		if (ret == -1) puts("Trapped!");
		else printf("Escaped in %d munute(s)\n", ret);
	}	
	
	return 0;
}
