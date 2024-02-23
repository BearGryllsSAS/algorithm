#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* 高精度乘模板 02 */

vector<int> mul(const vector<int>& A, const vector<int>& B)
{
	vector<int> C(100, 0);
	
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			C[i + j] += A[i] * B[j];
		}
	}
	
	int lenC = A.size() + B.size() - 1;
	
	for (int i = 0; i < lenC; i++)
	{
		if (C[i] >= 10)
		{
			C[i + 1] += C[i] / 10;
			
			C[i] %= 10;
		}
	}
	
	if (C[lenC]) lenC++;
	
	C.resize(lenC);
	
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	
	return C;
}

int main()
{
	string a, b;
	cin >> a >> b;
	
	vector<int> A, B;
	
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
	
	auto C = mul(A, B);
	
	for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	
	return 0;
}
