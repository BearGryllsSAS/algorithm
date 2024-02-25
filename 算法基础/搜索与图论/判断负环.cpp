#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

/* spfa 算法判断负环 */

const int N = 2010, M = 10010;

int n, m, x, y, z;
int h[N], e[M], w[M], ne[M], idx;
int d[N], cnt[N];
bool inQue[N];

void add(int x, int y, int z)
{
	e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

bool spfa()
{
	queue<int> myQue;
	
	for (int i = 1; i <= n; i++)										// 负环可能从 1 号点到不了	要把所有点加入进去	 
	{
		myQue.push(i);
		
		inQue[i] = true;
	}
	
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
				cnt[j] = cnt[it] + 1;
				if (cnt[j] >= n) return true;
				
				d[j] = d[it] + w[i];
				
				if (!inQue[j])
				{
					myQue.push(j);
					
					inQue[j] = true;
				}
			}
		}
	}
	
	return false;
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
	
	cout << (spfa() ? "Yes" : "No") << endl;
	
	return 0;
} 
