#include <iostream>
using namespace std;

/* 一维前缀和模板 */

const int N = 1e5 + 10;

int n, m, l, r;
int arr[N], s[N];

int main()
{
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + arr[i];
	
	while (m--)
	{
		scanf("%d%d", &l, &r);
		
		printf("---------- %d ----------\n", s[r] - s[l - 1]);
	} 
	
	return 0;
}
