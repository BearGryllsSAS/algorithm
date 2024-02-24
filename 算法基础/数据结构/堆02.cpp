#include <string.h>
#include <iostream>
using namespace std;

/* ¶ÑÄ£°å02 */

const int N = 1e5 + 10;

int size, m;
int h[N], ph[N], hp[N];

void h_swap(int a, int b) 
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a],h[b]);				// *********************
}

void down(int u) 
{
	int t = u;
	
	if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
	if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	
	if (t != u) 
	{
		h_swap(t, u);
		
		down(t);
	}
}

void up(int u) 
{
	while (u / 2 && h[u / 2] > h[u]) 
	{
		h_swap(u / 2, u);
		u /= 2;
	}
}

int main() 
{
	
	int N;
	scanf("%d", &N);
	
	while (N--) 
	{
		char op[10];
		int k, x;
		scanf("%s", op);
		
		if (!strcmp(op, "I")) 
		{
			scanf("%d", &x);
			
			size++, m++;
			
			ph[m] = size, hp[size] = m;
			
			h[size] = x;
			
			up(size);
		}
		else if (!strcmp(op, "PM")) 
		{
			printf("%d\n", h[1]);
		}
		else if (!strcmp(op, "DM")) 
		{
			h_swap(1, size);
			
			size--;
			
			down(1);
		}
		else if (!strcmp(op, "D")) 
		{
			scanf("%d", &k);
			
			k = ph[k];
			
			h_swap(k, size);
			
			size--;
			
			down(k), up(k);
		}
		else {
			scanf("%d%d", &k, &x);
			
			k = ph[k];
			
			h[k] = x;
			
			down(k), up(k);
		}
	}
	
	return 0;
}
