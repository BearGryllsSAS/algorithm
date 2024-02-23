#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
	int x, y;
	cin >> x >> y;
	
	if (abs(x) <= y)	// 在上方 
	{
		int n = y;
		
		cout << (LL)(2 * n - 1) * 2 * n + x - (-n) << endl; 
	}
	else if (abs(y) <= x)	// 在右边
	{
		int n = x;
		
		cout << (LL)2 * n * 2 * n + n - y << endl;	
	}
	else if (abs(x) <= abs(y) + 1)	// 在下方
	{
		int n = abs(y);
		
		cout << (LL)2 * n * (2 * n + 1) + n - x << endl;
	}
	else	// 在左边 
	{
		int n = abs(x);
		
		cout << (LL)(2 * n - 1) * (2 * n - 1) + y - (-n + 1) << endl;
	}
	
	return 0;
}
