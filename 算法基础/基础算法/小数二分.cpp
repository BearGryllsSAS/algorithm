#include <iostream>
using namespace std;

/* 小数二分模板 */

const double eps = 1e-8;		// 当两个数的差小于这个精度的时候，可以认为这就是结果了 

double n;

int main()
{
	scanf("%lf", &n);
	
	double l = 0, r = n, mid = -1;
	
	/*
	while (r - l > eps)
	{
		mid = (l + r) / 2;
		
		if (mid * mid > n) r = mid;
		else l = mid;
	}
	*/
	
	for (int i = 0; i < 100; i++)
	{
		mid = (l + r) / 2;
		
		if (mid * mid > n) r = mid;
		else l = mid;
	}
	
	printf("%f", l);
	
	return 0;
}
