#include <iostream>

using namespace std;

void mergeSort(long long array[ ], long left, long right)
{
	if(left<right-1)
	{
		long mid = (left+right-1)/2;
		
		//left half
		mergeSort(array, left, mid+1);
		
		//right half
		mergeSort(array, mid+1, right);
		
		//merge
		long leftIndex=left;
		long rightIndex=mid+1;
		long leftSize=(mid+1-left);
		long rightSize=(right-mid-1);
		
		long long leftArray[leftSize];
		long long rightArray[rightSize];
		
		for(int x=0;x<leftSize;x++)
		{
			leftArray[x] = array[leftIndex+x];
		}
		
		for(int x=0;x<rightSize;x++)
		{
			rightArray[x] = array[rightIndex+x];
		}
		
		leftIndex=0;
		rightIndex=0;
		long tempIndex=left;
		
		while(leftIndex<leftSize && rightIndex<rightSize)
		{
			if(leftArray[leftIndex]<=rightArray[rightIndex])
			{
				array[tempIndex] = leftArray[leftIndex];
				leftIndex++;
			}
			else
			{
				array[tempIndex] = rightArray[rightIndex];
				rightIndex++;
			}
			tempIndex++;
		}
		
		//insert remaining elements
		while(leftIndex<leftSize)
		{
			array[tempIndex] = leftArray[leftIndex];
			leftIndex++;
			tempIndex++;
		}
		while(rightIndex<rightSize)
		{
			array[tempIndex] = rightArray[rightIndex];
			rightIndex++;
			tempIndex++;
		}	
	}
}

int main()
{
	long n=0;
	cin >> n;
	long long sequence[n];
	
	for (long i=0;i<n;i++)
	{
		cin >> sequence[i];
	}
	
	mergeSort(sequence, 0, n);
	
	//print sorted sequence
	/*
	for(int y=0;y<n;y++)
		cout << sequence[y] << " ";
	*/
	
	//start counter for numbers
	long count=1;
	int res=0;

	for(int x=1;x<n;x++)
	{
		if(sequence[x]==sequence[x-1])
		{
			count++;
		}
		else
		{
			if(count>n/2)
			{
				break;
			}
			count=1;
		}
	}
	
	if(count>n/2)
	{
		res=1;
	}
	
	cout << res;
}
