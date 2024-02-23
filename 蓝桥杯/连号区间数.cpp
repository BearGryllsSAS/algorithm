#include <iostream>
using namespace std;

const int N = 10010, INF = 1000000;

int n;
int arr[N];


int main() 
{
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	
	int res = 0;
	
	for (int i = 0; i < n; i++) 
	{
		int maxV = -INF, minV = INF;
		
		for (int j = i; j < n; j++) 
		{
			maxV = max(maxV, arr[j]);
			minV = min(minV, arr[j]);
			
			if (maxV - minV == j - i) res++;
		}
	}
	
	cout << res << endl;
	
	return 0;
} 
