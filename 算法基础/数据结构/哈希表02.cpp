#include <cstring>
#include <iostream>
using namespace std;

/* 哈希表__开放地址法模板 */

const int N = 200003, null = 0x3f3f3f3f;							// N 一般为数据范围的两倍的第一个质数 

int n;
int arr[N];

char op[2];
int x;

int find(int x)
{
	int index = (x % N + N) % N;
	
	while (arr[index] != null && arr[index] != x) index = (index + 1) % N;
	
	return index;
}

int main()
{
	cin >> n;
	
	memset(arr, 0x3f, sizeof arr);
	
	while (n--)
	{
		scanf("%s%d", op, &x);
	
		int k = find(x);
		
		if (op[0] == 'I')
		{
			arr[k] = x;
		}
		else 
		{
			printf(arr[k] != null ? "Yes\n" : "No\n");
		}
	}
	
	return 0;
}
