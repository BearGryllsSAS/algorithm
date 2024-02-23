#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<int>& path, vector<vector<int>>& result, int startIndex, int m, int n) {
	
	if (path.size() + n - startIndex + 1 < m) return;
	
	if (path.size() == m) {
		
		result.push_back(path);
		
		return;
	}
	
	for (int i = startIndex; i <= n; i++) {
		
		path.push_back(i);
		
		dfs(path, result, i + 1, m, n);
		
		path.pop_back();
	}
}


int main() {

	int n, m;
	
	scanf("%d%d", &n, &m);
	
	vector<int> path;
	vector<vector<int>> result;
	
	dfs(path, result, 1, m, n);
	
	for (const auto& items : result) {
		for (const auto& item : items) {
			
			printf("%d ", item);
		}
		puts("");
	}
	
	return 0;
}
