#include <iostream>
using namespace std;

#define x first
#define y second

const int N = 1010;

typedef pair<int, int> PII;

int n;
char g[N][N];
bool st[N][N];
PII q[N * N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int i, int j, int& total, int& bround)
{
	int hh = 0, tt = -1;
	q[++tt] = {i, j};
	
	while (hh <= tt)
	{
		auto t = q[hh++];
		
		st[t.x][t.y] = true;
		
		total++;
		
		bool is_bround = false;
		
		for (int i = 0; i < 4; i++)
		{
			int x = t.x + dx[i], y = t.y + dy[i];
			
			if (x < 0 || x >= n || y < 0 || y >= n) continue;
			if (st[x][y]) continue;
			if (g[x][y] == '.') 
			{
				is_bround = true;
				continue;
			}
			
			q[++tt] = {x, y};
		}
		
		if (is_bround) bround++;
	}
}

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%s", g[i]);
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			if (g[i][j] == '#' && st[i][j] == false) 
			{
				int total = 0, bround = 0;
				
				bfs(i, j, total, bround);
				
				if (total == bround) cnt++;
			}	
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
