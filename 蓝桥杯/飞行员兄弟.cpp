#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define x first
#define y second

const int N = 5;

typedef pair<int, int> PII;

char g[N][N], backup[N][N];

void turn_one(int x, int y) {
	
	if (g[x][y] == '+') g[x][y] = '-';
	else g[x][y] = '+';
}

void turn_all(int x, int y) {
	
	for (int i = 0; i < 4; i++) {
		
		turn_one(x, i);
		
		turn_one(i, y);
	}
	
	turn_one(x, y);
}

int get(int x, int y) {
	
	return x * 4 + y;
}

int main() {
	
	for (int i = 0; i < 4; i++) cin >> g[i];
	
	vector<PII> res;
	
	for (int op = 1; op <= 1 << 16; op++) {
		
		memcpy(backup, g, sizeof g);
		
		vector<PII> temp;
		
		for (int i = 0; i < 4; i++) {
			
			for (int j = 0; j < 4; j++) {
				
				if (op >> get(i, j) & 1) {
					
					temp.push_back({i, j});
					
					turn_all(i, j);
				}
			}
		}
		
		bool flag = true;
		
		for (int i = 0; i < 4; i++) {
			
			for (int j = 0; j < 4; j++) {
				
				if (g[i][j] == '+')	flag = false;
			}
		}
		
		if (flag && (res.empty() || res.size() > temp.size())) res = temp;
		
		memcpy(g, backup, sizeof backup);
	}
 	
 	cout << res.size() << endl;
 	
 	for (const auto& item : res) cout << item.x + 1 << ' ' << item.y + 1 << endl;

	return 0;
}
