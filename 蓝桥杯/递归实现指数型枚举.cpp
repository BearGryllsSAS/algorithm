#include <iostream>
using namespace std;

/*
	在递归函数中直接打印输出结果是最快的
	
	要想收获结果最后再在 main 函数中打印的话，用 vector 是最方便的 
	
	要想收获结果最后再在 main 函数中打印的话，也可以用普通二维数组 int result[1 >> 15][16]，但是要注意在 main 中打印的时候，不打印 0 
*/


const int N = 16;

int n; 
int status[N];		// 记录每个数的状态：0---没有考虑	1---选择	2---不选择
 
void dfs(int u) {
	
	if (u > n) {
		// 递归终止条件，收获结果
		
		// 直接打印
		for (int i = 1; i <= n; i++) {
			
			if (status[i] == 1) printf("%d ", i);
		} 
		
		puts("");	// 打印回车
		
		return; 
	}
	
	// 选---向左递归 
	status[u] = 1;
	
	dfs(u + 1);			// 递归（含回溯） 
	
	status[u] = 0;		// 回溯---恢复现场---其实没必要 
	
	// 不选---向右递归 
	status[u] = 2;
	
	dfs(u + 1);			// 递归（含回溯） 
	
	status[u] = 0; 		// 回溯---回复现场---其实没必要 
}



int main() {

	cin >> n;
	
	dfs(1); 
	
	return 0;
}
