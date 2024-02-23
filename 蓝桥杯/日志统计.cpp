#include <algorithm>
#include <iostream>
using namespace std;

#define x first
#define y second

const int N = 1e5 + 10;

typedef pair<int, int> PII;

int n, d, k;
PII logs[N];
int cnt[N];
bool st[N];


int main()
{
	cin >> n >> d >> k;
	
	for (int i = 0; i < n; i++) scanf("%d%d", &logs[i].x, &logs[i].y);
	
	sort(logs, logs + n);
	
	for (int i = 0, j = 0; j < n; j++)
	{
		int id = logs[j].y;
		cnt[id]++;
		
		while (logs[j].x - logs[i].x >= d)
		{
			cnt[logs[i].y]--;
			i++;
		}
		
		if (cnt[id] >= k) st[id] = true;
	}
	
	for (int i = 0; i < 1e5 + 10; i++) 
	{
		if (st[i]) printf("%d\n", i);
	}
	
	return 0;
}
