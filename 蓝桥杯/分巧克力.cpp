#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, k;
int h[N], w[N];

bool check(int x) {
	
	int res = 0;
	
	// 分每一块巧克力 
	for (int i = 0; i < n; i++) {
		
		res += (h[i] / x) * (w[i] / x);
		
		if (res >= k) return true;
	}
	
	return false;
}

int main() {

	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < n; i++) scanf("%d%d", &h[i], &w[i]);
	
	int l = 1, r = 1e5, mid = -1;			// 二分巧克力的长度，找到数轴上满足要求的最右边的数 
	
	while (l < r) {
		
		mid = l + r + 1 >> 1;
		
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	
	printf("%d\n", l);
	
	return 0;
}
