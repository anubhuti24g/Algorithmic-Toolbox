#include <iostream>
using namespace std;

/*int Fib(int n)
{
	if (n<=1)
		return n;
	else
		return (Fib(n-1) + Fib(n-2));
}*/

long long FibFast(long long n)
{
	long long arr[n+1];
	arr[0]=0;
	arr[1]=1;
	for(long long i=2;i<(n+1);i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[n];
}

int main()
{
	long long n=0;
	cin >> n;
	cout << FibFast(n) << endl;
	//cout << Fib(n);
}
