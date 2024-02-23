#include <cstring>
#include <iostream>
using namespace std;

/* 染色法判断二分图 */

const int N = 1e5 + 10, M = 2 * N;

int n, m, u, v;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) {
	
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {
	
	color[u] = c;
	
	for (int i = h[u]; i != -1; i = ne[i]) {
		
		int j = e[i];
		
		if (!color[j]) {
			
			if (!dfs(j, 3 - c)) return false;
		}
		else if (color[j] == c) return false;
	}
	
	return true;
}

int main() {
	
	memset(h , -1, sizeof h);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		
		scanf("%d%d", &u, &v);
		
		add(u, v), add(v, u);
	}
	
	bool flag = true;
	
	for (int i = 1; i <= n; i++) {
		
		if (!color[i]) {
			
			if (!dfs(i, 1)) {
				
				flag = false;
				
				break; 
			}
		}
	}
	
	if (flag) puts("Yes");
	else puts("No");
	
	return 0;
}
