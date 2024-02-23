#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int get_seconds(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}

int get_time()
{
	string line;
	getline(cin, line);
	
	if (line.back() != '(') line += " (+0)";
	
	int h1, m1, s1, h2, m2, s2, d;
	sscanf(line.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
	
	return get_seconds(h2, m2, s2) - get_seconds(h1, m1, s1) + d * 24 * 3600;
}

int main() 
{
	int n;
	scanf("%d", &n);
	
	string line;
	getline(cin, line);
	
	while (n--)
	{
		int time = (get_time() + get_time()) / 2;
		
		int h = time / 3600, m = time % 3600 / 60, s = time % 60;
		
		printf("%02d:%02d:%02d\n", h, m, s);
	}
	
	return 0;
}
