#include <iostream>

using namespace std;

int CalcPosition (long long NoToBeChecked , long long arr[ ] , int initial , int final)
{
	if(final<initial)
		return -1;
	int mid = (initial + final)/2;
	int pos=-1;
	if (NoToBeChecked == arr[mid])
		pos = mid;
	else if(NoToBeChecked < arr[mid])
		pos = CalcPosition(NoToBeChecked, arr , initial , mid-1);
	else if(NoToBeChecked > arr[mid])
		pos = CalcPosition(NoToBeChecked, arr , mid+1 , final);
		
	return pos;
}


int main()
{
	int n=0;
	cin >> n;
	long long SortedArray[n];
	for(int i=0;i<n;i++)
	{
		cin >> SortedArray[i];
	}
	long k=0;
	cin >> k;
	long long NumbersToBeChecked[k];
	for(long j=0;j<k;j++)
	{
		cin >> NumbersToBeChecked[j];
	}
	
	int position;
	long long number;
	int start=0;
	for(long l=0;l<k;l++)
	{
		number = NumbersToBeChecked[l];
		position = CalcPosition(number , SortedArray , start , n);
		cout << position << " ";
	}
	
	
	
}
