#include <iostream>
using namespace std;

int main() {
	
	double x;
	
	cin >> x;
	
	double l = -10000, r = 10000, mid = -1;
	
	while (r - l > 1e-9) {
		
		mid = (l + r) / 2; 
		
		if (mid * mid * mid >= x) r = mid;
		else l = mid;
	}
	
	printf("%lf", mid);
}
