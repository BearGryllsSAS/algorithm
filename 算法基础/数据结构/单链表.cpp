#include <iostream>
using namespace std;

/* 单链表模板 */

const int N = 1e5 + 10;

int M;
int head, e[N], ne[N], idx;

// 初始化
void init() {
	head = -1, idx = 0;
}

// 插入一个数到头结点
void add_head(int x) {
	e[idx] = x, ne[idx] = head, head = idx++;
}

// 向第 k 个插入的数的后面插入一个数
void add_k(int k, int x) {
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
 }

// 删除头结点
void delete_head() {
	head = ne[head];
}

// 删除第 k 个插入的数的后面一个数 
void delete_k(int k) {
	ne[k] = ne[ne[k]];
}

int main() {
	cin >> M;
	
	init();
	
	while (M--) {
		char op;
		int k, x;
		
		cin >> op;
		
		// getchar();
		// scanf("%c", &op);
		
		if (op == 'H') {
			scanf("%d", &x);
			
			add_head(x);
		}
		else if (op == 'D') {
			scanf("%d", &k);
			
			if (k == 0) delete_head();
			else delete_k(k - 1);
		}
		else {
			scanf("%d%d", &k, &x);
			
			add_k(k - 1, x);
		}
		
		printf("op = %c\n", op);
	}
	
	for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
	
	return 0;
}
