#include <iostream>
using namespace std;

/* 快速排序模板 */

const int N = 1e6 + 10;

int n;
int arr[N];

// j 和 j + 1		l		l + r >> 1
// i - 1 和 i 		r 		l + r + 1 >> 1

void quicksort(int arr[], int l, int r)
{
	if (l >= r) return;
	
	int x = arr[r], i = l - 1, j = r + 1;
	
	while (i < j)
	{
		do i++; while (arr[i] < x);
		do j--; while (arr[j] > x);
		
		if (i < j) swap(arr[i], arr[j]);
	}
	
	quicksort(arr, l, i - 1), quicksort(arr, i, r);
}

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	quicksort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	
	return 0;
}
