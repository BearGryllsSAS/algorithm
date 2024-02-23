#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

/* 堆优化版的迪杰斯特拉算法 */

const int N = 1e5 + 10;

typedef pair<int, int> PII;

int n, m, x, y, z;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool visit[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {

	memset(d, 0x3f, sizeof d);
	d[1] = 0;

	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0, 1 });

	while (!heap.empty()) {
		auto it = heap.top();
		heap.pop();

		int cur = it.second, distance = it.first;

		if (visit[cur]) continue;
		visit[cur] = true;

		for (int i = h[cur]; i != -1; i = ne[i]) {
			
			int j = e[i];								// *****************************

			if (d[j] > distance + w[i]) {

				d[j] = distance + w[i];

				heap.push({ d[j], j });
			}
		}
	}

	return d[n] == 0x3f3f3f3f ? -1 : d[n];
}

int main() {

	memset(h, -1, sizeof h);
	
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);

		add(x, y, z);
	}

	cout << dijkstra() << endl;

	return 0;
}

