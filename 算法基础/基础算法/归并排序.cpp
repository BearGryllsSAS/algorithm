#include <iostream>
using namespace std;

/* 归并排序模板 */

const int N = 1e6 + 10;

int n;
int arr[N];
int temp[N];

void mergesort(int arr[], int l, int r)
{
	if (l >= r) return;
	
	int mid = l + r >> 1;
	
	mergesort(arr, l, mid), mergesort(arr, mid + 1, r);										// 递归分组
	
	int index = 0, i = l, j = mid + 1;
	
	while (i <= mid && j <= r) temp[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];			// 归并两个数组 
	
	while (i <= mid) temp[index++] = arr[i++];
	while (j <= r) temp[index++] = arr[j++];
	
	for (int i = l, j = 0; i <= r; i++, j++) arr[i] = temp[j];								// 放回原位（注意下标） 
}


int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	mergesort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	
	return 0;
}
