#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

// 优化版的 bellmanFord 算法
// 只要图中没有负环就可以用 SPFA 算法（99.99%） ，但是限制最多 k 条边的题目只能用 Bellman Ford 算法 
// 大部分 dijkstra 算法都能用 spfa 来做，而且性能更好 
/* SPFA 算法模板 */

const int N = 1e5 + 10;

int n, m, x, y, z;
int h[N], e[N], w[N], ne[N], idx;
int d[N];
bool inQue[N];

void add(int x, int y, int z)
{
	e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

int spfa()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	
	queue<int> myQue;
	myQue.push(1);
	inQue[1] = true;
	
	while (!myQue.empty()) 
	{
		int it = myQue.front();
		myQue.pop();
		
		inQue[it] = false;
		
		for (int i = h[it]; i != -1; i = ne[i])
		{
			int j = e[i];
			
			if (d[j] > d[it] + w[i])
			{
				d[j] = d[it] + w[i];
				
				if (!inQue[j]) 
				{
					myQue.push(j);
					
					inQue[j] = true;	
				}
			}
		}
	}
	
	return d[n] > 0x3f3f3f3f / 2 ? -1 : d[n];
}

int main()
{
	memset(h, -1, sizeof h);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		
		add(x, y, z);
	}
	
	int result = spfa();
	
	if (result == -1) puts("impossible");
	else cout << result << endl;
	
	return 0;
}

