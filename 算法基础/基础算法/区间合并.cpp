#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* 区间合并 */

const int N = 1e5 + 10;

typedef pair<int, int> PII;

int n, l, r;
vector<PII> arr;

void merge(vector<PII>& arr)
{
	vector<PII> res;
	
	sort(arr.begin(), arr.end());
	
	int st = INT_MIN, ed = INT_MIN;
	
	for (auto& item : arr)
	{
		if (item.first > ed)
		{
			if (ed != INT_MIN) res.push_back({st, ed});
			
			st = item.first, ed = item.second;
		}
		else
		{
			ed = max(ed, item.second);
		}
	}
	
	if (ed != INT_MIN) res.push_back({st, ed});
	
	arr = res;
}

int main()
{
	cin >> n;
	
	while (n--)
	{
		scanf("%d%d", &l, &r);
		
		arr.push_back({l, r});
	}
	
	merge(arr);
	
	cout << arr.size() << endl;
	
	return 0;
}

