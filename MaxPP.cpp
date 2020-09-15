#include <iostream>
#include <cstdint>

using namespace std;

/*long long MaxPairwiseProduct(long long arrofnos[ ], long long arrsize)
{
	//why is .size() not working?!
	long arrsize = 0;
	long i=0;
	while(arrofnos[i]!='\0')
	{
		arrsize++;
		i++;
		//cout << arrofnos[i] << endl;
	}
	//8cout << arrsize << endl;
	//n = *(&arrofnos + 1) - arrofnos;
	//array<int,5> myInts;
	//cout << myInts.size();
	//n = sizeof(arrofnos)/sizeof(arrofnos[0]);
	//cout << sizeof(arrofnos) << " " << sizeof(arrofnos[0]) << endl;
	//cout << "n = " << n << endl;
	//for(int a=0;a<n;a++)
	//	cout << arrofnos[a] << " ";
	long maxIndex1 = -1;
	long maxIndex2 = -1;
	for (long k=0;k<arrsize;k++)
	{
		if (arrofnos[k]>arrofnos[maxIndex1])
		{
			maxIndex1=k;
			//cout << maxIndex1 << " ";
		}
	}
	for (long j=0;j<arrsize;j++)
	{
		if(j==maxIndex1)
		{
			continue;
		}
		if (arrofnos[j]>arrofnos[maxIndex2])
		{
			maxIndex2=j;
			//cout << maxIndex1 << " ";
		}
	}
	long long n1= arrofnos[maxIndex1];
	long long n2= arrofnos[maxIndex2];
	long long result = n1*n2;
	
	return result;
}*/

int main()
{
	//defining size of array and creating it
	long n = 0;
	cin >> n;
	uint64_t arr_of_nos[n];
	for (long i=0;i<n;i++)
		cin >> arr_of_nos[i];
		
	/*stress testing
	int n = (rand() % 50)+2;
	int arr_of_nos[n];
	for (int i=0;i<n;i++)
	{
		arr_of_nos[i] = (rand()%100000);
		cout << arr_of_nos[i] << " ";
	}
	cout << endl;*/
	
	//choosing maximum 2 numbers
	/*int temp=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr_of_nos[j]<arr_of_nos[j+1])
			{
				temp=arr_of_nos[j];
				arr_of_nos[j]=arr_of_nos[j+1];
				arr_of_nos[j+1]=temp;
			}
		}
	}*/
	
	long maxIndex1 = 0;
	long maxIndex2 = 0;
	for (int k=1;k<n;k++)
	{
		if (arr_of_nos[k]>arr_of_nos[maxIndex1])
		{
			maxIndex1=k;
		}
	}
	if(maxIndex1==0)
		maxIndex2=1;
	
	for (int j=0;j<n;j++)
	{
		if(j==maxIndex1)
		{
			continue;
		}
		if (arr_of_nos[j]>arr_of_nos[maxIndex2])
		{
			maxIndex2=j;
		}
	}
	
	uint64_t result = arr_of_nos[maxIndex1]*arr_of_nos[maxIndex2];
	cout << result ;
	//long long nresult = MaxPairwiseProduct(arr_of_nos,n);
	//cout << nresult << "\n";
	return 0;
	
}


