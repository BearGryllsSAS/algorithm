#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

typedef long long LL;

int n;
int a[N], b[N], c[N];
int as[N];				// as[i] 表示在 a[] 中有多少个数小于 b[i] 
int cs[N];				// cs[i] 表示在 c[] 中有多少个数大于 b[i]
int cnt[N], s[N]; 

int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]++;
	for (int i = 0; i < n; i++) scanf("%d", &b[i]), b[i]++;
	for (int i = 0; i < n; i++) scanf("%d", &c[i]), c[i]++;
	
	// 求 as[]
	for (int i = 0; i < n; i++) cnt[a[i]]++;
	for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
	for (int i = 0; i < n; i++) a[i] = s[b[i] - 1];
	
	memset(&cnt, 0, sizeof(cnt));
	memset(&s, 0, sizeof(s));
	
	// 求 cs[] 
	for (int i = 0; i < n; i++) cnt[c[i]]++;
	for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
	for (int i = 0; i < n; i++) c[i] = s[N - 1] - s[b[i]];
	
	LL res = 0;
	for (int i = 0; i < n; i++) res += (LL)a[i] * c[i];
	
	cout << res << endl;
	
	return 0;
} 
