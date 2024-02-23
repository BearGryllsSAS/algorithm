#include <cstring>
#include <iostream>
using namespace std;

/* ÐÙÑÀÀûËã·¨Ä£°å */

const int N = 510, M = 1e5 + 10;

int n1, n2, m, u, v;
int h[N], e[M], ne[M], idx;
int match[N];
bool visit[N];

void add(int a, int b) {
	
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool Find(int u) {
	
	for (int i = h[u]; i != -1; i = ne[i]) {
		
		int j = e[i];
		
		if (!visit[j]) {
			
			visit[j] = true;
			
			if (match[j] == 0 || Find(match[j])) {
				
				match[j] = u;
				
				return true;
			}
		}
	}
	
	return false;
}

int main() {
	
	memset(h, -1, sizeof h);
	
	scanf("%d%d%d", &n1, &n2, &m);
	
	for (int i = 0; i < m; i++) {
		
		scanf("%d%d", &u, &v);
		
		add(u, v);
	}
	
	int res = 0;
	
	for (int i = 1; i <= n1; i++) {
		
		memset(visit, false, sizeof visit);
		
		if (Find(i)) res++; 
	}
	
	printf("%d\n", res);
	
	return 0;
}
