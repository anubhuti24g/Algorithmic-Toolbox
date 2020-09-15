#include <iostream>
using namespace std;

long long FibFastLastDigit(long long n)
{
	long long arr[n+1];
	arr[0]=0;
	arr[1]=1;
	for(long long i=2;i<(n+1);i++)
	{
		arr[i]=(arr[i-1]%10)+(arr[i-2]%10);
	}
	return arr[n]%10;
}

int main()
{
	long long n=0;
	cin >> n;
	cout << FibFastLastDigit(n) << endl;
}
