#include <iostream>
using namespace std;

/* ×Ö·û´®¹þÏ£Ä£°å */

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

int n, m;
char str[N];
ULL h[N], p[N];

ULL hash_string(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
	scanf("%d%d%s", &n, &m, str + 1);
	
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	
	while (m--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		
		if (hash_string(l1, r1) == hash_string(l2, r2)) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
