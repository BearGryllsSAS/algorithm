#include <cstring>
#include <iostream>
using namespace std;

/* BFS Ä£°å */

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];
PII q[N * N], pre[N][N];

int bfs() {
	int hh = 0, tt = -1;
	q[++tt] = {0, 0};
	
	memset(d, -1, sizeof d);
	d[0][0] = 0;
	
	int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	
	while (hh <= tt) {
		auto it = q[hh++];
		
		for (int i = 0; i < 4; i++) {
			int x = it.first + dx[i], y = it.second + dy[i];
			
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
				d[x][y] = d[it.first][it.second] + 1;
				
				pre[x][y] = {it.first, it.second};
				
				q[++tt] = {x, y};
			}
		}
	}
	
	int x = pre[n - 1][m - 1].first, y = pre[n - 1][m - 1].second;
	while (x || y) {
		cout << '(' << x << ", " << y << ')' << endl;
		
		int temp = x;
		x = pre[x][y].first; 
		y = pre[temp][y].second;
	}
	
	return d[n - 1][m - 1];
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &g[i][j]);
		}
	}
	
	cout << bfs() << endl;
	
	return 0;
}
