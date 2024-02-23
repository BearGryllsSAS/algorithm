#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

/* spfa À„∑®≈–∂œ∏∫ª∑ */

const int N = 2010, M = 10010;

int n, m, x, y, z;
int h[N], e[M], ne[M], w[M], idx;
int d[N], cnt[N];
bool inQue[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
	
	queue<int> myQue;
	
	for (int i = 1; i <= n; i++) {
		myQue.push(i);
		
		inQue[i] = true;
	}
	
	while (!myQue.empty()) {
		
		int t = myQue.front();
		myQue.pop();
		
		inQue[t] = false;
		
		for (int i = h[t]; i != -1; i = ne[i]) {
			
			int j = e[i];
			
			if (d[j] > d[t] + w[i]) {
				
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				
				d[j] = d[t] + w[i];
				
				if (!inQue[j]) {
					
					myQue.push(j);
					
					inQue[j] = true;
				}
			}
		}
	}
	
	return false;
}

int main() {
	
	memset(h, -1, sizeof h);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		
		scanf("%d%d%d", &x, &y, &z);
		
		add(x, y, z);
	}
	
	if (spfa()) puts("Yes");
	else puts("No");
	
	return 0;
}
