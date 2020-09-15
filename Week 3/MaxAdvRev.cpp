#include <iostream>

using namespace std;

int main()
{
	int n=0;
	cin >> n;
	long a[n],b[n];
	for (int i=0;i<n;i++)
		cin >> a[i];
	for (int l=0;l<n;l++)
		cin >> b[l];
		
	long temp1=0,temp2=0;
	for (int oj=0;oj<n;oj++)
	{
		for (int j=1;j<n;j++)
		{
			if(a[j]<a[j-1])
			{
				temp1=a[j-1];
				a[j-1]=a[j];
				a[j]=temp1;
			}
			if(b[j]<b[j-1])
			{
				temp2=b[j-1];
				b[j-1]=b[j];
				b[j]=temp2;
			}	
		}	
	}
	//for(int h=0;h<n;h++)
	//	cout << a[h] << " " << b[h] << endl;
	
	long maxOutput=0;
	for (int k=0;k<n;k++)
	{
		maxOutput+=a[k]*b[k];
	}
	
	cout << maxOutput;
}
