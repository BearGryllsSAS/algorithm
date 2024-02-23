#include <iostream>
using namespace std;

// 能处理负权，但是不能有负权回路。
// 邻接矩阵结构存储图的时候要考虑重边（取最小），邻接表则不用 。 
// 求最短路的时候，如果边权全为正的话，不用考虑自环。
// 求最短路的时候，用邻接矩阵存储，如果有负权边且存在负环的话，d[i == j] = 0。  
/* Floyd 算法模板 */

const int N = 210, INF = 1e9;

int n, m, k, x, y, z;
int d[N][N];

void floyd() {
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			if (i == j) d[i][j] = 0;
			
			d[i][j] = INF;
		}
	}
	
	for (int i = 0; i < m; i++) {
		
		scanf("%d%d%d", &x, &y, &z);
		
		d[x][y] = z;
	}
	
	floyd();
	
	while (k--) {
		
		scanf("%d%d", &x, &y);
		
		if (d[x][y] > INF / 2) puts("impossible");
		else printf("%d\n", d[x][y]);
	}
	
	return 0;
}
