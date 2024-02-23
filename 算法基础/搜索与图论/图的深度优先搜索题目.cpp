#include <cstring>
#include <iostream>
using namespace std;

/* 图的深度优先搜索___邻接表题目 */

const int N = 1e5 + 10, M = 2 * N;

int ans = N;
int n, a, b;
int h[N], e[M], ne[M], idx;
int visit[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int u) {
	visit[u] = 1;
	
	int size = 0, sum = 0;
	
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		
		if (visit[j]) continue;
		
		int s = bfs(j);
		
		size = max(size, s);
		
		sum += s;
	}
	
	size = max(size, n - sum - 1);
	ans = min(ans, size);
	
	return sum + 1;
}

int main() {
	memset(h, -1, N);
	
	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		
		add(a, b); add(b, a);
	}
	
	bfs(1);
	
	cout << ans << endl;
	
	return 0;
}
