#include <iostream>
using namespace std;

/* ˫����ģ�� */

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;

// ��ʼ��
void init() {
	// 0 �����˵�
	// 1 ����Ҷ˵�
	
	idx = 2;
	
	r[0] = 1, l[1] = 0;
}

// ���±��� k �ĵ�ĺ������ x
void add_d(int k, int x) {
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx;
}

// ɾ���±��� k �ĵ�
void delete_k(int k) {
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
 

int main() {
	
	return 0;
}
