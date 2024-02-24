#include <iostream>
using namespace std;

/* 单调队列模板 */

const int N = 1e5 + 10;

int n, k;
int arr[N];
int q[N], hh, tt = -1;

int main()
{
	scanf("%d%d", &n, &k);
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		
		while (hh <= tt && arr[q[tt]] >= arr[i]) tt--;
		
		q[++tt] = i;
		
		if (i >= k - 1) printf("%d ", arr[q[hh]]);
	}
	
	puts("");	
	
	hh = 0, tt = -1;									// 还原 
	
	for (int i = 0; i < n; i++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh++;
		
		while (hh <= tt && arr[q[tt]] <= arr[i]) tt--;
		
		q[++tt] = i;
		
		if (i >= k - 1) printf("%d ", arr[q[hh]]);
	}
	
	return 0;	
} 
