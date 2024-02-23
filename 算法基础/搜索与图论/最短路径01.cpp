#include <cstring>
#include <iostream>
using namespace std;

// ���·���Ȩֵ���������򲻹��Ի����Ի���Ȼ������������·�У�����������ر���ѡȨֵ��С�ı� 
/* �Ͻ�˹�����㷨ģ�� */

const int N = 510;

int n, m, x, y, z;
int g[N][N];
int d[N];
bool visit[N];

int dijkstra() {
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	
	for (int i = 0; i < n; i++) {
		int t = -1;
		
		for (int j = 1; j <= n; j++) {
			if (!visit[j] && (t == -1 || d[t] > d[j])) t = j;
		}
		
		visit[t] = true;
		
		for (int j = 1; j <= n; j++) d[j] = min(d[j], d[t] + g[t][j]);
	}
	
	return d[n] == 0x3f3f3f3f ? 1 : d[n];
}

int main() {
	scanf("%d%d", &n, &m);
	
	memset(g, 0x3f, sizeof g);
	
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		
		g[x][y] = min(g[x][y], z);
	}
	
	cout << dijkstra() << endl;
	
	return 0;
}
