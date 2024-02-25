#include <cstring>
#include <iostream>
using namespace std;

/* 图的广度优先遍历题目 */

const int N = 1e5 + 10;

int n, m, a, b;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
	memset(d, -1, sizeof d);
	d[1] = 0;
	
	int hh = 0, tt = -1;
	q[++tt] = 1;
	
	while (hh <= tt)
	{
		int it = q[hh++];
		
		for (int i = h[it]; i != -1; i = ne[i])
		{
			int j = e[i];
			
			if (d[j] == -1)
			{
				d[j] = d[it] + 1;
				
				q[++tt] = j;	
			}	
		}	
	}	
	
	return d[n];
}


int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		
		add(a, b);
	}
	
	cout << bfs() << endl;
	
	return 0;
}
 
