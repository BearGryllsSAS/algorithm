#include <iostream>
using namespace std;

/* ������ģ�� */

const int N = 1e5 + 10;

int M;
int head, e[N], ne[N], idx;

// ��ʼ��
void init() {
	head = -1, idx = 0;
}

// ����һ������ͷ���
void add_head(int x) {
	e[idx] = x, ne[idx] = head, head = idx++;
}

// ��� k ����������ĺ������һ����
void add_k(int k, int x) {
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
 }

// ɾ��ͷ���
void delete_head() {
	head = ne[head];
}

// ɾ���� k ����������ĺ���һ���� 
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
