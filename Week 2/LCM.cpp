#include <iostream>
using namespace std;

long long GCDFast(long long n1, long long n2)
{
	long gcdno=1;
	long long a1 = n2%n1;
	if (a1!=0)
	{
		GCDFast(a1,n1);
	}
	else
	{
		return n1;
	}
	
}

long long LCM(long long product, long long gcdvalue)
{
	return product/gcdvalue;
}

int main()
{
	long long n,m;
	cin >> n >> m;
	int gcd = GCDFast(n,m);
	long long prod = n*m;
	cout << LCM(prod,gcd);
}
