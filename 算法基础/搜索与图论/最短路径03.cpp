#include <cstring>
#include <iostream>
using namespace std;

// 处理有负权边的问题，如果有负权回路的话，最短路不一定存在 
/* Bellman Ford 算法模板 */

const int N = 510, M = 10010;

struct Edge{
	
	int a, b, w;
	
}edges[M];

int n, m, k, x, y, z;
int d[N], backup[N];

int bellman_ford() {
	
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	
	for (int i = 0; i < k; i++) {
		
		memcpy(backup, d, sizeof d);
		
		for (int j = 0; j < m; j++) {
			
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			
			d[b] = min(d[b], backup[a] + w);
		}
	}
	
	return d[n] == 0x3f3f3f3f / 2 ? -1 : d[n];
}

int main() {
	
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 0; i < m; i++) {
		
		scanf("%d%d%d", &x, &y, &z);
		
		edges[i] = { x, y, z };
	}
	
	int result = bellman_ford();
	
	if (result == -1) cout << "impossible" << endl;
	else cout << result << endl;
	
	return 0;
}


