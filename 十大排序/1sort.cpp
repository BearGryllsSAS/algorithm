#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int arr[N];

// 冒泡排序 
void bubblesort1(int arr[], int len)
{
	if (len < 2) return;
	
	for (int j = len - 1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
		}
	}
	
	return;
}

// 冒泡排序优化 
void bubblesort1_Plus(int arr[], int len)
{
	if (len < 2) return;
	
	bool flag = true;
	
	for (int j = len - 1; j > 0 && flag; j--)
	{
		flag = false;
		
		for (int i = 0; i < j; i++)
		{
			if (arr[i] > arr[i + 1]) 
			{
				swap(arr[i], arr[i + 1]);
				
				flag = true;	
			}
		}
	}
	
	return;
}

// 递归冒泡排序 
void bubblesort2(int arr[], int len)
{
	if (len < 2) return;
	
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
	}
	
	bubblesort2(arr, len - 1);
	
	return;
}

// 递归冒泡排序优化 
void bubblesort2_Plus(int arr[], int len)
{
	if (len < 2) return;
	
	bool flag = false;
	
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) 
		{
			swap(arr[i], arr[i + 1]);
			
			flag = true;	
		}
	}
	
	if (!flag) return;
	
	bubblesort2(arr, len - 1);
	
	return;
}





// 选择排序
void selectsort1(int arr[], int len)
{
	if (len < 2) return;
	
	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex]) minIndex = j;
		}
		
		if (minIndex != i) swap(arr[minIndex], arr[i]);
	}
} 

// 选择排序优化 
void selectsort1_Plus(int arr[], int len)
{
	if (len < 2) return;
	
	int iLeft = 0, iRight = len - 1;
	int minIndex = 0, maxIndex = 0;
	
	while (iLeft < iRight)
	{
		minIndex = maxIndex = iLeft;
		
		for (int i = iLeft; i <= iRight; i++)
		{
			if (arr[i] < arr[minIndex]) minIndex = i;
			
			if (arr[i] > arr[maxIndex]) maxIndex = i;
		}
		
		if (minIndex != iLeft) swap(arr[minIndex], arr[iLeft]);
		
		if (maxIndex == iLeft) maxIndex = minIndex;
		
		if (maxIndex != iRight) swap(arr[maxIndex], arr[iRight]);
		
		iLeft++, iRight--;
	}
}

// 递归选择排序
void selectsort2(int arr[], int len)
{
	if (len < 2) return;
	
	int i = 0;
	int minIndex = 0;
	
	for (i = 1; i < len; i++)
	{
		if (arr[i] < arr[minIndex]) minIndex = i;
	}
	
	if (minIndex != 0) swap(arr[minIndex], arr[0]);
	
	selectsort2(arr + 1, len - 1);
	
	return;
}

// 递归选择排序优化
void selectsort2_Plus(int arr[], int len)
{
	if (len < 2) return;
	
	int iLeft = 0, iRight = len - 1;
	int minIndex = 0, maxIndex = 0;
	
	for (int i = iLeft; i <= iRight; i++)
	{
		if (arr[i] < arr[minIndex]) minIndex = i;
		
		if (arr[i] > arr[maxIndex]) maxIndex = i;
	}
	
	if (minIndex != iLeft) swap(arr[minIndex], arr[iLeft]);
	
	if (maxIndex == iLeft) maxIndex = minIndex;
	
	if (maxIndex != iRight) swap(arr[maxIndex], arr[iRight]);
	
	selectsort2_Plus(arr + 1, len - 2);
	
	return;
}





// 插入排序
void insertsort(int arr[], int len)
{
	if (len < 2) return;
	
	for (int i = 1; i < len; i++)
	{
		int temp = arr[i];
		
		int j = 0;
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		
		arr [j + 1] = temp;
	}
	
	return;
} 





// 希尔排序
void shellsort(int arr[], int len)
{
	if (len < 2) return;
	
	for (int step = len / 2; step > 0; step /= 2)
	{
		for (int i = 0; i < step; i++)
		{
			[=]()
			{
				for (int ii = i + step; ii < len; ii += step)
				{
					int temp = arr[ii];
					
					int jj = 0;
					for (jj = ii - step; jj >= 0 && arr[jj] > temp; jj -= step) arr[jj + step] = arr[jj];
					
					arr[jj + step] = temp;
				}
				
				return;
			}();
		}
	}
	
	return;
}





// 快速排序
// j 和 j + 1		这种情况不能写 r (l + r << 1)
// i - 1 和 i		这种情况不能写 l (l + r + 1 << 1)
void quicksort(int q[], int l, int r) 
{
	if (l >= r) return;
	
	int x = q[l], i = l - 1, j = r + 1;
	
	while (i < j) 
	{
		do i++; while(q[i] < x);
		do j--; while(q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	
	quicksort(q, l, j);
	quicksort(q, j + 1, r);
}





// 归并排序
int temp[N];
void mergesort(int q[], int l, int r)
{
	if (l >= r) return;
	
	int mid = l + r >> 1;
	
	mergesort(q, l, mid), mergesort(q, mid + 1, r);
	
	int i = l, j = mid + 1, k = 0;
	
	while (i <= mid && j <= r) temp[k++] = q[i] < q[j] ? q[i++] : q[j++];
	
	while (i <= mid) temp[k++] = q[i++];
	while (j <= r) temp[k++] = q[j++];
	
	for (int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
	
	return;
}





// 堆排序
void heapsort(int q[], int u, int size)
{
	int t = u;
	
	if (u * 2 <= size && q[u * 2] < q[t]) t = u * 2;
	if (u * 2 + 1 <= size && q[u * 2 + 1] < q[t]) t = u * 2 + 1;
	
	if (t != u)
	{
		swap(q[t], q[u]);
		
		heapsort(arr, t, size);	
	}
}





// 计数排序
void countsort1(int q[], int len)
{
	if (len < 2) return;
	
	int maxNum = [=]() -> int
	{
		int maxNum = q[0];
		
		for (int i = 1; i < len; i++)
		{
			if (q[i] > maxNum) maxNum = q[i];
		}
		
		return maxNum;
	}();
	
	int temp[maxNum + 1] = {0};
	
	for (int i = 0; i < len; i++) temp[q[i]]++;
	
	int index = 0;
	
	for (int i = 0; i < maxNum + 1; i++)
	{
		for (int j = 0; j < temp[i]; j++) q[index++] = i;
	}
}





// 计数排序优化
void countsort2(int q[], int len)
{
	if (len < 2) return;
	
	int minNum = *min_element(q, q + len);
	int maxNum = *max_element(q, q + len);
	
	int temp[maxNum - minNum + 1] = {0};
	
	for (int i = 0; i < len; i++) temp[q[i] - minNum]++;
	
	int index = 0;
	
	for (int i = 0; i < maxNum - minNum + 1; i++)
	{
		for (int j = 0; j < temp[i]; j++) q[index++] = i + minNum;
	}
} 





// 桶排序 --- 思想重要，关键在于决策
void bucketsort(int q[], int len)
{
	if (len < 2) return;
	
	int bucket[10000][10] = {0};
	int bucketsize[10000] = {0};
	
	for (int i = 0; i < len; i++) bucket[q[i] / 10][bucketsize[q[i] / 10]++] = q[i];
	
	for (int i = 0; i < 10000; i++) quicksort(bucket[i], 0, bucketsize[i] - 1);
	
	int index = 0;
	
	for (int i = 0; i < 10000; i++)
	{
		for (int j = 0; j < bucketsize[i]; j++) arr[index++] = bucket[i][j];
	}
}





// 基数排序
void radixsort(int q[], int len)
{
	
}

 

int main()
{	
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	// bubblesort1(arr, n);
	
	// selectsort1(arr, n);
	
	// insertsort(arr, n);
	
	// shellsort(arr, n);
	
	// quicksort(arr, 0, n - 1);
	
	// mergesort(arr, 0, n - 1);
	
	// countsort1(arr, n);
	
	// bucketsort(arr, n);
	
	radixsort(arr, n);
	
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);	


//	cin >> n;
//	
//	int size = n;
//	
//	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
//	
//	for (int i = n / 2; i > 0; i--) heapsort(arr, i, size);
//	
//	while (n--)
//	{
//		printf("%d ", arr[1]);
//		
//		swap(arr[1], arr[size--]);
//		
//		heapsort(arr, 1, size);
//	}

	return 0;
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
