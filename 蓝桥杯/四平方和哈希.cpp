#include <unordered_map>
#include <iostream>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

unordered_map<int, PII> myMap;

int n;

int main() {
	
	scanf("%d", &n);
	
	for (int c = 0; c * c <= n; c++) {
		
		for (int d = c; c * c + d * d <= n; d++) {
			
			int t = c * c + d * d;
			
			if (myMap.count(t) == 0) myMap[t] = {c, d};
		}
	}
	
	for (int a = 0; a * a <= n; a++) {
		
		for (int b = a; a * a + b * b <= n; b++) {
			
			int t = n - (a * a + b * b);
			
			if (myMap.count(t)) {
				
				printf("%d %d %d %d\n", a, b, myMap[t].x, myMap[t].y);
				
				return 0;
			}
		}
	}
	
	return 0;
}
