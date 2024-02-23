#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	sort(a, a + n);
	
	int d = 0;
	for (int i = 1; i < n; i++) d = gcd(d, a[i] - a[0]);
	
	if (!d) printf("%d\n", n);
	else printf("%d\n", (a[n - 1] - a[0]) / d + 1);
	
	return 0;
}
