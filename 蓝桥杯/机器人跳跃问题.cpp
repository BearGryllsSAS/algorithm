#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, maxH;
int h[N];

bool check(int e) {
	
	for (int i = 1; i <= n; i++) {
		
		e = 2 * e - h[i];
		
		if (e >= maxH) return true;
		if (e < 0) return false;
	}
	
	return true;
}

int main() {
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		
		scanf("%d", &h[i]);
		
		if (h[i] > maxH) maxH = h[i];
	}
	
	int l = 0, r = maxH, mid = -1;
	
	while (l < r) {
		
		mid = l + r >> 1;
		
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	
	printf("%d", l);
	
	return 0;
}
