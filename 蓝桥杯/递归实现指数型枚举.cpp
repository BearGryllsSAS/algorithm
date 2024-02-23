#include <iostream>
using namespace std;

/*
	�ڵݹ麯����ֱ�Ӵ�ӡ������������
	
	Ҫ���ջ���������� main �����д�ӡ�Ļ����� vector ������ 
	
	Ҫ���ջ���������� main �����д�ӡ�Ļ���Ҳ��������ͨ��ά���� int result[1 >> 15][16]������Ҫע���� main �д�ӡ��ʱ�򣬲���ӡ 0 
*/


const int N = 16;

int n; 
int status[N];		// ��¼ÿ������״̬��0---û�п���	1---ѡ��	2---��ѡ��
 
void dfs(int u) {
	
	if (u > n) {
		// �ݹ���ֹ�������ջ���
		
		// ֱ�Ӵ�ӡ
		for (int i = 1; i <= n; i++) {
			
			if (status[i] == 1) printf("%d ", i);
		} 
		
		puts("");	// ��ӡ�س�
		
		return; 
	}
	
	// ѡ---����ݹ� 
	status[u] = 1;
	
	dfs(u + 1);			// �ݹ飨�����ݣ� 
	
	status[u] = 0;		// ����---�ָ��ֳ�---��ʵû��Ҫ 
	
	// ��ѡ---���ҵݹ� 
	status[u] = 2;
	
	dfs(u + 1);			// �ݹ飨�����ݣ� 
	
	status[u] = 0; 		// ����---�ظ��ֳ�---��ʵû��Ҫ 
}



int main() {

	cin >> n;
	
	dfs(1); 
	
	return 0;
}
