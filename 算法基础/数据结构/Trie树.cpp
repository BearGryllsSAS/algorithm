#include <iostream>
using namespace std;

/* Trie Ê÷Ä£°å */

const int N = 1e5 + 10;

int n;
char str[N];
int son[N][26], cnt[N], idx;

void Insert(char str[]) {
	int p = 0;
	
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		
		if (!son[p][u]) son[p][u] = ++idx;
		
		p = son[p][u];
	}
	
	cnt[p]++;
}

int Query(char str[]) {
	int p = 0;
	
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		
		if (!son[p][u]) return 0;
		
		p = son[p][u];
	}
	
	return cnt[p];
}

int main() {
	scanf("%d", &n);
	
	while (n--) {
		char op[2];
		scanf("%s%s", op, str);
		
		if (op[0] == 'I') {
			Insert(str);
		}
		else {
			printf("%d\n", Query(str));
		}
	}
	
	return 0;
}
