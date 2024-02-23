#include <iostream>
using namespace std;

/* 朴素并查集模板 */

const int N = 1e5 + 10;

int n, m;
int p[N];
int a, b;
char op[2];

int Find(int x) {
	if (p[x] != x) p[x] = Find(p[x]);
	return p[x];
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) p[i] = i;
	
	while (m--) {
		scanf("%s%d%d", op, &a, &b);
		
		if (op[0] == 'M') {
			p[Find(a)] = Find(b);
		}
		else {
			if (Find(a) == Find(b)) puts("Yes");
			else puts("No");
		}
	}
	
	return 0;
}
