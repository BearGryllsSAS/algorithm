#include <iostream>
using namespace std;

/* 双指针模板 */
/*
	双指针很巧妙，没有特定的模板，一般都是：遍历后（j）指针，作为右边界；前指针（i）是从前往后遍历的，每一轮遍历 i 都有可能往后移动，一般不往前移动 
*/

const int N = 1e5 + 10;

int n;
int arr[N], visit[N];

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	int res = 0;
	
	for (int j = 0, i = 0; j < n; j++)
	{
		visit[arr[j]]++;
		
		while (visit[arr[j]] > 1) visit[arr[i++]]--;
		
		res = max(res, j - i + 1);
	}
	
	cout << res << endl;
	
	return 0;
}
