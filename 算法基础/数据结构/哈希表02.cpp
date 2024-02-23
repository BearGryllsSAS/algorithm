#include <cstring>
#include <iostream>
using namespace std;

/* 哈希表___开放地址法模板 */

const int N = 1e5 + 3, null = 0x3f3f3f3f;

int h[N];

int Find(int x) {
	int index = (x % N + N) % N;
	
	while (h[index] != null && h[index] != x) index = (index + 1) % N;
	
	return index;
}

int main() {
	int n;
	cin >> n;
	
	memset(h, 0x3f, N);
	
	while (n--) {
		char op[2]; int x;
		scanf("%s%d", op, &x);
		
		int k = Find(x);
		
		if (op[0] == 'I') h[k] = x;
		else {
			if (h[k] != null) puts("Yes");
			else puts("No");
		}
	}
	
	
	return 0;
}
