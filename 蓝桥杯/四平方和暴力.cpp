#include <cmath>
#include <iostream>
using namespace std;

int n;

int main() {
	
	scanf("%d", &n);
	
	for (int a = 0; a * a <= n; a++) {
		
		for (int b = a; a * a + b * b <= n; b++) {
			
			for (int c = b; a * a + b * b + c * c <= n; c++) {
				
				int t1 = n - (a * a + b * b + c * c);
				
				int t2 = sqrt(t1);
				
				if (t2 * t2 == t1) {
					
					printf("%d %d %d %d\n", a, b, c, t2);
					
					return 0;
				}		
			}
		}
	}
	
	return 0;
}
