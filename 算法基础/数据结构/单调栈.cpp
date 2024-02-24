#include <iostream>
using namespace std;

/* µ¥µ÷Õ»Ä£°å */

const int N = 1e5 + 10;

int n, x;
int st[N], tt;

int main()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		
		while (tt && st[tt] >= x) tt--;
		
		if (tt) printf("%d ", st[tt]);
		else printf("-1 ");
		
		st[++tt] = x;
	}
	
	return 0;
}
