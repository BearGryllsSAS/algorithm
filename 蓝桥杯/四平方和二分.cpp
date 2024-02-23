#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2500;

struct Sum {
	
	int s, c, d;
	
	bool operator < (const Sum& t) const {
		
		if (s != t.s) return s < t.s;
		if (c != t.c) return c < t.c;
		return d < t.d;
	}
} sum[N];

int n, index;

int main() {
	
	scanf("%d", &n);
	
	for (int c = 0; c * c <= n; c++) {
		
		for (int d = c; c * c + d * d <= n; d++) {
			
			sum[index++] = {c * c + d * d, c, d};
		}
	}
	
	sort(sum, sum + index);
	
	for (int a = 0; a * a <= n; a++) {
		
		for (int b = a; a * a + b * b <= n; b++) {
			
			int t = n - (a * a + b * b);
			
			int l = 0, r = index - 1, mid = -1;
			
			while (l < r) {
				
				mid = l + r >> 1;
				
				if (sum[mid].s >= t) r = mid;
				else l = mid + 1;
			}
			
			if (sum[l].s == t) {
				
				printf("%d %d %d %d", a, b, sum[l].c, sum[l].d);
				
				return 0;
			}
		}
	}
	
	return 0;
}
