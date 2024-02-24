#include <cstring>
#include <iostream>
using namespace std;

/* 哈希表___拉链法模板 */

const int N = 1e5 + 10;

int n;
int head[N], e[N], ne[N], idx;

char op[2];
int x;

void insert(int x)
{
	int index = (x % N + N) % N;
	
	e[idx] = x;
	ne[idx] = head[index];
	head[index] = idx++;
} 

bool query(int x)
{
	int index = (x % N + N) % N;
	
	for (int i = head[index]; i != -1; i = ne[i])
	{
		if (e[i] == x) return true;	
	}
	
	return false;
}

int main()
{
	cin >> n;
	
	memset(head, -1, sizeof head);
	
	while (n--)
	{
		scanf("%s%d", op, &x);
		
		if (op[0] == 'I')
		{
			insert(x);
		}
		else
		{
			printf(query(x) ? "Yes\n" : "No\n");
		}
	}

	return 0;
}
