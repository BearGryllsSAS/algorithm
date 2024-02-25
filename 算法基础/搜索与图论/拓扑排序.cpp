#include <cstring>
#include <iostream>
using namespace std;

/* ÍØÆËÅÅĞòÄ£°å */

const int N = 1e5 + 10;

int n, m, x, y;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int x, int y)
{
	e[idx] = y, ne[idx] = h[x], h[x] = idx++;	
} 

bool topSort()
{
	int hh = 0, tt = -1;
	
	for (int i = 1; i <= n; i++)
	{
		if (!d[i]) q[++tt] = i;
	}
	
	while (hh <= tt)
	{
		int it = q[hh++];
		
		for (int i = h[it]; i != -1; i = ne[i])
		{
			int j = e[i];
			
			if (--d[j] == 0) q[++tt] = j;
		}
	}
	
	return tt == n - 1;
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		
		add(x, y);
		
		d[y]++;
	}
	
	if (topSort()) 
	{
		for (int i = 0; i < n; i++) printf("%d ", q[i]);
	}
	else 
	{
		printf("-1");
	}
	
	puts("");
	
	return 0;
}
