#include <iostream>
using namespace std;

/* ¶ÑÄ£°å 01 */

const int N = 1e5 + 10;

int n, m;
int heap[N], size;

void down(int u)
{
	int t = u;
	
	if (u * 2 <= size && heap[u * 2] < heap[t]) t = u * 2;
	if (u * 2 + 1 <= size && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1;
	
	if (t != u)
	{
		swap(heap[t], heap[u]);
		
		down(t);
	}
	
	return;
}

int main()
{
	cin >> n >> m;
	
	size = n;
	
	for (int i = 1; i <= n; i++) scanf("%d", &heap[i]);
	
	for (int i = n / 2; i > 0; i--) down(i);
	
	while (m--)
	{
		printf("%d ", heap[1]);
		
		heap[1] = heap[size--];
		
		down(1);
	}
	
	return 0;
}
