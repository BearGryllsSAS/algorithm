#include <iostream>
using namespace std;

// �ܴ���Ȩ�����ǲ����и�Ȩ��·��
// �ڽӾ���ṹ�洢ͼ��ʱ��Ҫ�����رߣ�ȡ��С�����ڽӱ����� �� 
// �����·��ʱ�������ȨȫΪ���Ļ������ÿ����Ի���
// �����·��ʱ�����ڽӾ���洢������и�Ȩ���Ҵ��ڸ����Ļ���d[i == j] = 0��  
/* Floyd �㷨ģ�� */

const int N = 210, INF = 1e9;

int n, m, k, x, y, z;
int d[N][N];

void floyd() {
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			if (i == j) d[i][j] = 0;
			
			d[i][j] = INF;
		}
	}
	
	for (int i = 0; i < m; i++) {
		
		scanf("%d%d%d", &x, &y, &z);
		
		d[x][y] = z;
	}
	
	floyd();
	
	while (k--) {
		
		scanf("%d%d", &x, &y);
		
		if (d[x][y] > INF / 2) puts("impossible");
		else printf("%d\n", d[x][y]);
	}
	
	return 0;
}
