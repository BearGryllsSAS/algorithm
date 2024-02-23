#include <iostream>
using namespace std;

/* 整数二分模板 */

const int N = 1e5 + 10;

int n, q, k;
int arr[N];


int main()
{
	scanf("%d%d", &n, &q);
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	while (q--)
	{
		scanf("%d", &k);
		
		int l = 0, r = n - 1, mid = -1;
		while (l < r)
		{
			mid = l + r >> 1;						// r = mid
			
			if (arr[mid] >= k) r = mid;				// 不断逼近 r ，让 r 更往左 
			else l = mid + 1;
		}
		
		if (arr[r] != k) printf("-1 -1\n");
		else 
		{
			printf("%d ", r);
			
			l = 0, r = n - 1;
			while (l < r)
			{
				mid = l + r + 1 >> 1;				// l = mid
				
				if (arr[mid] <= k) l = mid;			// 不断逼近 l ，让 l 更往右 
				else r = mid - 1;
			}
			
			printf("%d\n", l);
		}
	}
	
	return 0;
}
