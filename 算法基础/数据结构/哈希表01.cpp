#include <cstring>
#include <iostream>
using namespace std;

/* 哈希表___拉链法模板*/

const int N = 1e5 + 3;

int h[N], e[N], ne[N], idx;

void Insert(int x) {
	int index = (x % N + N) % N;
	
	e[idx] = x;
	ne[idx] = h[index];
	h[index] = idx++;
}

bool Find(int x) {
	int index = (x % N + N) % N;
	
	for (int i = h[index]; i != -1; i = ne[i]) {
		if (e[i] == x) return true;
	}
	
	return false;
}

int main() {
	int n;
	cin >> n;
	
	memset(h, -1, N);

	while (n--) {
		char op[2]; int x;
		scanf("%s%d", op, &x);
		
		if (op[0] == 'I') Insert(x);
		else {
			if (Find(x)) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}
