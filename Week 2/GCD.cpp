#include <iostream>
using namespace std;

/*int GCD(long long n1, long long n2)
{
	long gcdno=1;
	for(long long i=2;i<=n1;i++)
	{
		if(n1%i==0 && n2%i==0)
		{
			gcdno=i;	
		}
	}
	
	return gcdno;
}*/

int GCDFast(long long n1, long long n2)
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

int main()
{
	long long n1, n2;
	cin >> n1 >> n2;
	if(n1>n2)
	{
		int a=n1;
		n1=n2;
		n2=a;
	}
	cout << GCDFast(n1, n2) << endl;
	//cout << GCD(n1, n2);
}
