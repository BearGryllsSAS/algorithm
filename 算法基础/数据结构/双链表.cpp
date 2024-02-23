#include <iostream>
using namespace std;

/* 双链表模板 */

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;

// 初始化
void init() {
	// 0 存放左端点
	// 1 存放右端点
	
	idx = 2;
	
	r[0] = 1, l[1] = 0;
}

// 在下标是 k 的点的后面插入 x
void add_d(int k, int x) {
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx;
}

// 删除下标是 k 的点
void delete_k(int k) {
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
 

int main() {
	
	return 0;
}
