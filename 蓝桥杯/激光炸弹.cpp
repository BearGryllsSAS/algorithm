#include <iostream>
using namespace std;

const int N = 5010;

int cnt, r, n, m;
int x, y, w;
int s[N][N];


int main() 
{	
	cin >> cnt >> r;
	
	r = min(r, 5001);
	
	// n = m = r;
	
	while (cnt--) 
	{	
		cin >> x >> y >> w;
		
		x++, y++;
		
		n = max(n, x), m = max(m, y);
		
		s[x][y] += w;
	}
	
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++)
		{
			s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
		}
	}
	
	int res = 0;
	
	for (int i = r; i <= n; i++) 
	{
		for (int j = r; j <= m; j++) 
		{
			res = max(res, s[i][j] - s[i][j - r] - s[i - r][j] + s[i - r][j - r]);
		}
	}
	
	cout << res;
	
	return 0;
}
