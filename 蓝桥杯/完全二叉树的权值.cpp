#include <limits>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

typedef long long LL;

int n;
int a[N];

int main()
{
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	LL maxth = LLONG_MIN;
	int deep = 0;
	
	for (int i = 1, d = 1; i <= n; i *= 2, d++)
	{
		LL path = 0;
		
		for (int j = i; j < i + (1 << d - 1) && j <= n; j++) path += a[j];
		
		if (path > maxth)
		{
			maxth = path;
			
			deep = d;
		}
	}
	
	cout << deep << endl;
	
	return 0;
}
