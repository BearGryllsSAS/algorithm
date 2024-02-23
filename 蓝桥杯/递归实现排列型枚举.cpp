#include <iostream>
using namespace std;

const int N = 10;

int n;
int status[N]; 		// 表示每一个坑的状态：0---未考虑	1~i---表示有元素
bool visit[N];		// 标记一下每个数是否已经被选中 

void dfs(int u) {
	
	if (u > n) {
		// 递归终止条件，收获结果
		
		for (int i = 1; i <= n; i++) printf("%d ", status[i]);
		
		puts("");
		
		return; 
	}
	
	// 递归的宽度（递归搜索树的宽度），遍历每一个数 
	for (int i = 1; i <= n; i++) {
		
		if (!visit[i]) {		// 如果该数字未被选中 
			
			visit[i] = true;
			status[i] = i;
			
			dfs(u + 1);
			
			visit[i] = false;
			status[i] = 0;
		}
	} 
}


int main() {
	
	cin >> n;
	
	dfs(1);
	
	return 0;
}
