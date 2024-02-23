#include <algorithm>
#include <iostream>
using namespace std;

/* 克鲁斯卡尔算法模板 */

const int N = 1e5 + 10, M = 2e5 + 10;

struct Edge{
	
	int a, b, w;
	
	bool operator < (const Edge& W) const {
		
		return w < W.w;
	}
	
}edges[M];

int n, m, u, v, w;
int p[N];

int Find(int u) {
	
	if (p[u] != u) p[u] = Find(p[u]);
	
	return p[u];
}

int main() {
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		
		scanf("%d%d%d", &u, &v, &w);
		
		edges[i] = {u, v, w};
	}
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	int res = 0, cnt = 0;
	
	for (int i = 0; i < m; i++) {
		
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		
		a = Find(a), b = Find(b);
		
		if (a != b) {
			
			p[a] = b;
			
			res += w, cnt++;
		}
	}
	
	if (cnt != n - 1) puts("impossible");
	else printf("%d\n", res);
	
	return 0;
}
