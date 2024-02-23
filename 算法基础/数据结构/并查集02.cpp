#include <iostream>
using namespace std;

/* 维护 size 的并查集*/

const int N = 1e5 + 10;

int n, m;
int p[N], size[N];

int Find(int x) {
	if (p[x] != x) p[x] = Find(p[x]);
	return p[x];
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		size[i] = 1;
	}
	
	while (m--) {
		char op[3];
		int a, b;
		scanf("%s", op);
		
		if (op[0] == 'C') {
			scanf("%d%d", &a, &b);
			
			if (a == b) continue;
			
			size[Find(b)] += size[Find(a)];
			
			p[Find(a)] = Find(b);
		}
		else if (op[1] == '1') {
			scanf("%d%d", &a, &b);
			
			if (Find(a) == Find(b)) puts("Yes");
			else puts("No");
		}
		else {
			scanf("%d", &a);
			
			printf("%d\n", size[Find(a)]);
		}
	}
	
}
