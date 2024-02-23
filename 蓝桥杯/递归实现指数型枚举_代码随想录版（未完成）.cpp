#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<int>& path, vector<vector<int>>& result, vector<bool>& visit, int index, int n) {
	
	if (index > n) return;
	if (!path.empty()) {
		
		result.push_back(path);
	}
	
	for (int i = index; i <= n; i++) {
		
		if (!visit[i]) {
			
			visit[i] = true;
			path.push_back(i);
			
			dfs(path, result, visit, index + 1, n);
			
			visit[i] = false;
			path.pop_back();
		}
	}
}

int main() {
	
	int n;
	cin >> n;
	
	vector<bool> visit(n + 1, false);
	
	vector<int> path;
	vector<vector<int>> result;
	
	dfs(path, result, visit, 1, n);
	
	for (const auto& items : result) {
		for (const auto& item : items) {
			printf("%d ", item);
		}
		puts("");
	}
	
	return 0;
}
