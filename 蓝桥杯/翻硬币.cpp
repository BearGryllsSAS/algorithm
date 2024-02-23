#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int len;
char start[N], aim[N];

void turn(int index) {
	
	if (start[index] == '*') start[index] = 'o';
	else start[index] = '*';
}

int main() {
	
	cin >> start >> aim;
	
	len = strlen(start);
	
	int res = 0;
	
	for (int i = 0; i < len - 1; i++) {
		
		if (start[i] != aim[i]) {
			
			turn(i);		// ¿ÉÒÔÊ¡ÂÔ 
			
			turn(i + 1);
			
			res++;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
