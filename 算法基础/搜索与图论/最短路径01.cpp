#include <cstring>
#include <iostream>
using namespace std;

/* ÆÓËØ dijkstra Ëã·¨Ä£°å */

const int N = 510;

int n, m, x, y, z;
int g[N][N], d[N];
bool visit[N];

int dijkstra()
{
	memset(d, 0x3f, sizeof d);	
	d[1] = 0;
	
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		
		for (int j = 1; j <= n; j++)
		{
			if (!visit[j] && (t == -1 || d[t] > d[j])) t = j;
		}
		
					
		visit[t] = true;
			
		for (int j = 1; j <= n; j++) d[j] = min(d[j], d[t] + g[t][j]);
	}
	
	return d[n] == 0x3f3f3f3f ? -1 : d[n];
}


int main()
{
	memset(g, 0x3f, sizeof g);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		
		g[x][y] = min(g[x][y], z);
	}
	
	cout << dijkstra() << endl;
	
	return 0;
}
