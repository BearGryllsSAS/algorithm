#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 10010;

int n;
int a[N];

int main()
{
	int cnt;
	cin >> cnt;
	
	string line;
	
	getline(cin, line);			// 忽略第一行的回车
	
	while (cnt--) 
	{
		getline(cin, line);
		
		stringstream ssin(line);
		
		while (ssin >> a[n]) n++;
	}
	
	sort(a, a + n);
	
	int res1 = 0, res2 = 0;
	
	for (int i = 1; i < n; i++) 
	{
		if (a[i] - a[i - 1] > 1) res1 = a[i] - 1;
		
		if (a[i] == a[i - 1])  res2 = a[i];
	}
	
	cout << res1 << ' ' << res2 << endl;
	
	return 0;
}
