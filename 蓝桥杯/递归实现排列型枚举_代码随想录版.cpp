#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<int>& path, vector<vector<int>>& result, vector<bool>& visit, int n) {
	
	if (path.size() == n) {
		
		result.push_back(path);
		
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		
		if (!visit[i]) {
			
			visit[i] = true;
			path.push_back(i);
			
			dfs(path, result, visit, n);
			
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
	
	dfs(path, result, visit, n);
	
	for (const auto& items : result) {
		for (const auto& item : items) {
			printf("%d ", item);
		}
		puts("");
	}
	
	return 0;
}
