#include <iostream>
using namespace std;

const int N = 10010;

int n;
int b[N];
bool st[N];

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	
	// 找不同的环 
	int cnt = 0;			
	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			cnt++;
			
			for (int j = i; !st[j]; j = b[j])
			{
				st[j] = true;
			}
		}
	}
	
	cout << n - cnt << endl;
	
	return 0;
}
