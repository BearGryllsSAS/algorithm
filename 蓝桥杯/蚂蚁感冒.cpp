#include <iostream>
using namespace std;

const int N = 55;

int n;
int arr[N];

int main() 
{
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int left = 0, right = 0;		// 分别表示 左边向右走 右边向左走 的蚂蚁的数量
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > 0 && abs(arr[i]) < abs(arr[0])) left++;
		if (arr[i] < 0 && abs(arr[i]) > abs(arr[0])) right++;	
	}
	
	if ((arr[0] > 0 && right == 0) || (arr[0] < 0 && left == 0)) cout << 1 << endl;
	else cout << left + right + 1 << endl;
	
	return 0;
}
