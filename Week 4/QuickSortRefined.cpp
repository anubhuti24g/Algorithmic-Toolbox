#include <iostream>

using namespace std;

void threeWayPartition(long long array[ ], long left, long right)
{
	if(left>=right)
		return;
	long long pivot=array[left];
	long partOneEnd=left;
	long long temp=0;
	
	//assigning all elements their position right or left wrt pivot element
	for(long j=left+1;j<right;j++)
	{
		if(array[j]<=pivot)
		{
			//swap
			partOneEnd++;
			temp=array[j];
			array[j]=array[partOneEnd];
			array[partOneEnd]=temp;
		}
	}
	
	long partTwoEnd=partOneEnd;
	
	//separating equal elements, and elements smaller than
	for(long k=left+1;k<=partOneEnd;k++)
	{
		if(array[k]==pivot)
		{
			//swap
			temp=array[k];
			array[k]=array[partOneEnd];
			array[partOneEnd]=temp;
			partOneEnd--;
		}
	}
	
	//placing pivot element along with its other occurences
	long tempA = array[partOneEnd];
	array[partOneEnd]=array[left];
	array[left]=tempA;
	
	//assigning pivot element indices
	long pivotIndex1 = partOneEnd;
	long pivotIndex2 = partTwoEnd;
	
	//print positions and array to check
	/*
	cout << "poe: " << partOneEnd << endl;
	cout << "pte: " << partTwoEnd << endl;
	cout << "pi1: " << pivotIndex1 << endl;
	cout << "pi2: " << pivotIndex2 << endl;
	//cout << "pivotIndex: " << pivotIndex << endl;
	
	for(long k=0;k<right;k++)
		cout << array[k] << " ";
	cout << endl;
	*/
	
	threeWayPartition(array, left, pivotIndex1);
	threeWayPartition(array, pivotIndex2+1, right);

}

int main()
{
	long n=0;
	cin >> n;
	long long inputArray[n];
	for(long i=0;i<n;i++)
		cin >> inputArray[i];
	
	int initial=0;
	threeWayPartition(inputArray, initial, n);
	
	for(long x=0;x<n;x++)
		cout << inputArray[x] << " ";
	cout << endl;
}

