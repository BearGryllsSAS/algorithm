#include <iostream>
using namespace std;

const int N = 10;

int n;
int status[N]; 		// ��ʾÿһ���ӵ�״̬��0---δ����	1~i---��ʾ��Ԫ��
bool visit[N];		// ���һ��ÿ�����Ƿ��Ѿ���ѡ�� 

void dfs(int u) {
	
	if (u > n) {
		// �ݹ���ֹ�������ջ���
		
		for (int i = 1; i <= n; i++) printf("%d ", status[i]);
		
		puts("");
		
		return; 
	}
	
	// �ݹ�Ŀ�ȣ��ݹ��������Ŀ�ȣ�������ÿһ���� 
	for (int i = 1; i <= n; i++) {
		
		if (!visit[i]) {		// ���������δ��ѡ�� 
			
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
