#include <iostream>
using namespace std;

int main() {
	
	int n;
	
	scanf("%d", &n);
	
	/*				用数组实现，递推版本 
	int f[47];
	f[1] = 0;
	f[2] = 1;
	
	for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
	
	for (int i = 1; i <= n; i++) printf("%d ", f[i]);
	*/
	
	/*				不用数组实现，优化版本 
	int a = 0, b = 1;
	
	for (int i = 1; i <= n; i++) {
		
		printf("%d ", a);
		
		int fn = a + b;
		
		a = b;
		
		b = fn;
	}
	*/
		
	return 0;
}
