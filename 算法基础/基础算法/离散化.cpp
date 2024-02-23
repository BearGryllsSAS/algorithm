#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* 离散化模板 */
// 值域大，值的个数少，有些时候要用到这些值来做数组下标，离散化能把这些序列映射到连续的自然数，使得空间更节省

const int N = 3 * 1e5 + 10;

typedef pair<int, int> PII;

int n, m, x, c, l, r;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
	int l = 0, r = alls.size() - 1, mid = -1;
	
	while (l < r)
	{
		mid = l + r >> 1;
		
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	
	return r + 1;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &c);
		
		add.push_back({x, c});
		
		alls.push_back(x);
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		
		query.push_back({l, r});
		
		alls.push_back(l), alls.push_back(r);
	}
	
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	for (const auto& item : add) a[find(item.first)] += item.second;
	
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];
	
	for (const auto& item : query) printf("---------- %d ----------\n", s[find(item.second)] - s[find(item.first) - 1]);
	
	return 0;
}
