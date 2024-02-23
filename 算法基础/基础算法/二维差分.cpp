#include <iostream>
using namespace std;

/* 二维差分模板 */

const int N = 1010;

int n, m, q;
int x1, y1, x2, y2, c;
int s[N][N], arr[N][N];

void insert(int arr[N][N], int x1, int y1, int x2, int y2, int c)
{
	arr[x1][y1] += c;
	arr[x2 + 1][y1] -= c;
	arr[x1][y2 + 1] -= c;
	arr[x2 + 1][y2 + 1] += c;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &s[i][j]);
			
			insert(arr, i, j, i, j, s[i][j]);
		}
	}
	
	while (q--)
	{
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		
		insert(arr, x1, y1, x2, y2, c);
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
			
			printf("%d ", arr[i][j]);
		}
		puts("");
	}
	
	return 0;
}
