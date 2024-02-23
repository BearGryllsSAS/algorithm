#include <iostream>
using namespace std;

/* ¶ÑÄ£°å01 */

const int N = 1e5 + 10;

int n, m;
int h[N], size;

void down(int u) {
	int t = u;
	
	if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
	if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	
	if (t != u) {
		swap(h[t], h[u]);
		
		down(t);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	size = n;
	
	for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
	
	for (int i = n / 2; i > 0; i--) down(i);
	
	while (m--) {
		printf("%d ", h[1]);
		
		h[1] = h[size--];
		
		down(1);
	}
	
	return 0;
}
