#include <iostream>
using namespace std;

/* 位运算 */
// （1）求n的第k位数字: n >> k & 1
// （2）返回n的最后一位1：lowbit(n) = n & -n = n & (~n + 1)

int n, num;

int main()
{
	scanf("%d", &n);
	
	while (n--)
	{
		scanf("%d", &num);
		
		int res = 0;
		
		while (num)
		{
			num -= num & -num;
			
			res++;
		}
		
		/*
		for (int i = 0; i < 32; i++)
		{
			if (num >> i & 1) res++;
		}
		*/
		
		printf("%d ", res);
	}
	
	return 0;
}
