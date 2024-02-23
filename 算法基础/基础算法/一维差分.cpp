#include <iostream>
using namespace std;

/* 一维差分模板 */

const int N = 1e5 + 10;

int n, m, l, r, c;
int s[N], arr[N];

void insert(int arr[], int l, int r, int x)
{
	arr[l] += x;
	arr[r + 1] -= x;
}

int main()
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		
		insert(arr, i, i, s[i]);
	}
	
	while (m--)
	{
		scanf("%d%d%d", &l, &r, &c);
		
		insert(arr, l, r, c);
	}
	
	for (int i = 1; i <= n; i++)
	{
		arr[i] += arr[i - 1];
		
		printf("%d ", arr[i]);
	}
	
	return 0;
}
