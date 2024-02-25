#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

/* 堆优化版的 dijkstra 模板 */
// 一般不用 

const int N = 1e5 + 10;

typedef pair<int, int> PII;

int n, m, x, y, z;
int h[N], e[N], w[N], ne[N], idx;
int d[N];
bool visit[N];

void add(int x, int y, int z)
{
	e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx++;
}

int dijkstra()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});
	
	while (!heap.empty())
	{
		auto it = heap.top();
		heap.pop();
		
		int cur = it.second, distance = it.first;
		
		if (visit[cur]) continue;
		visit[cur] = true;
		
		for (int i = h[cur]; i != -1; i = ne[i])
		{
			int j = e[i];
			
			if (d[j] > distance + w[i])					// 这里是 w[i]	一定要注意 
			{
				d[j] = distance + w[i];
				
				heap.push({d[j], j});
			}
		}
	}
	
	return d[n] == 0x3f3f3f3f ? -1 : d[n];
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
	
	cout << dijkstra() << endl;
	
	return 0;
}

