#include <cstring>
#include <iostream>
using namespace std;

/* Õÿ∆À≈≈–Úƒ£∞Â */

const int N = 1e5 + 10, M = 2 * N;

int n, m, x, y;
int h[N], e[M], ne[M], idx;
int q[N], d[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topSort() {
	int hh = 0, tt = -1;
	
	for (int i = 1; i <= n; i++) {
		if (!d[i]) q[++tt] = i;
	}
	
	while (hh <= tt) {
		int it = q[hh++];
		
		for (int i = h[it]; i != -1; i = ne[i]) {
			int j = e[i];
			
			if (--d[j] == 0) q[++tt] = j;
 		}
	}
	
	return tt == n - 1;
}

int main() {
	memset(h, -1, N);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		
		add(x, y);
		
		d[y]++;
	}

	if (topSort()) {
		for (int i = 0; i < n; i++) cout << q[i] << ' ';
		cout << endl;
	}
	else cout << "-1" << endl;
	
	return 0;
}
