#include <iostream>
using namespace std;

/* ×Ö·û´®¹þÏ£Ä£°å */

const int N = 1e5 + 10, P = 131;

typedef unsigned long long ULL;

int n, m, l1, r1, l2, r2;
char str[N];
int p[N], h[N];

void init()
{
	p[0] = 1, h[0] = 0;
	
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * P, h[i] = h[i - 1] * P + str[i];
		
	return;
}

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	scanf("%d%d%s", &n, &m, str + 1);
	
	init();
	
	while (m--)
	{
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		
		printf(get(l1, r1) == get(l2, r2) ? "Yes\n" : "No\n");
	}
	
	return 0;
}
