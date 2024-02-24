#include <iostream>
using namespace std;

/* 维护 size 的并查集模板 */

const int N = 1e5 + 10;

int n, m;
int p[N], size[N];

char op[3]; 
int a, b;

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	
	return p[x];
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) p[i] = i, size[i] = 1;
	
	while (m--)
	{
		scanf("%s", op);
		
		if (op[0] == 'C')
		{
			scanf("%d%d", &a, &b);
			
			if (a == b) continue;
			
			size[find(b)] += size[find(a)];
			
			p[find(a)] = find(b);	
		}
		else if (op[1] == '1')
		{
			scanf("%d%d", &a, &b);
			
			printf(find(a) == find(b) ? "Yes\n" : "No\n");
		}
		else
		{
			scanf("%d", &a);
			
			printf("%d\n", size[find(a)]);
		}
	}

	return 0;
}
