#include <cstring>
#include <iostream>
using namespace std;

/* 图的深度优先搜索___邻接表模板 */

const int N = 1e5 + 10, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int visit[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
	visit[u] = true;
	
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		
		if (visit[j]) dfs(j);
	}
}


int main() {
	
	memset(visit, -1, N);
	
	return 0;
}
