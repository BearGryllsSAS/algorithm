#include <cstring>
#include <iostream>
using namespace std;

/* 图的深度优先搜索题目 */

const int N = 1e5 + 10, M = 2 * N;

int n, m, a, b;
int h[N], e[M], ne[M], idx;
int q[N], d[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs() {
	int hh = 0, tt = -1;
	q[++tt] = 1;
	
	memset(d, -1, N);
	d[1] = 0;
	
	while (hh <= tt) {
		int it = q[hh++];
		
		for (int i = h[it]; i != -1; i = ne[i]) {
			int j = e[i];
			
			if (d[j] == -1) {
				d[j] = d[it] + 1;
				
				q[++tt] = j;
			}
		}
	}
	
	return d[n];
} 

int main() {
	memset(h, -1, N);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		
		add(a, b);
	}
	
	cout << bfs() << endl;
	
	return 0;
}
