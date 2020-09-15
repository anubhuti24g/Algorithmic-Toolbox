#include <iostream>

using namespace std;

void threeWayPartition(long long array[ ][2], long left, long right)
{
	if(left>=right)
		return;
	long long pivot=array[left][0];
	long partOneEnd=left;
	long long tempA=0;
	long long tempB=0;
	
	//assigning all elements their position right or left wrt pivot element
	for(long j=left+1;j<right;j++)
	{
		if(array[j][0]<=pivot)
		{
			//swap
			partOneEnd++;
			
			tempA=array[j][0];
			array[j][0]=array[partOneEnd][0];
			array[partOneEnd][0]=tempA;
			
			tempB=array[j][1];
			array[j][1]=array[partOneEnd][1];
			array[partOneEnd][1]=tempB;
		}
	}
	
	long partTwoEnd=partOneEnd;
	
	//separating equal elements, and elements smaller than
	for(long k=left+1;k<=partOneEnd;k++)
	{
		if(array[k][0]==pivot)
		{
			//swap
			tempA=array[k][0];
			array[k][0]=array[partOneEnd][0];
			array[partOneEnd][0]=tempA;
			
			tempB=array[k][1];
			array[k][1]=array[partOneEnd][1];
			array[partOneEnd][1]=tempB;
			
			partOneEnd--;
		}
	}
	
	//placing pivot element along with its other occurences
	tempA = array[partOneEnd][0];
	array[partOneEnd][0]=array[left][0];
	array[left][0]=tempA;
	
	tempB = array[partOneEnd][1];
	array[partOneEnd][1]=array[left][1];
	array[left][1]=tempB;
	
	//assigning pivot element indices
	long pivotIndex1 = partOneEnd;
	long pivotIndex2 = partTwoEnd;
	
	threeWayPartition(array, left, pivotIndex1);
	threeWayPartition(array, pivotIndex2+1, right);

}

int main()
{
	//input
	long s, p;
	cin >> s >> p;
	long long segment[s][2];
	long long points[p];
	for (int i=0;i<s;i++)
		cin >> segment[i][0] >> segment[i][1];

	for (int j=0;j<p;j++)
	{
		cin >> points[j];
	}
	
	//sort given segments in ascending order according to 1st element of each segment
	threeWayPartition(segment, 0, s);
	
	//print and check if array is sorted
	/*
	for(int nm=0;nm<s;nm++)
		cout << segment[nm][0] << " " << segment[nm][1] << endl;
	*/	
	
	//define counter for counting number of occurences
	long counter;
	for(int pcount=0;pcount<p;pcount++)
	{
		//set counter=0 for each no
		counter=0;
		for(int check=0;check<s;check++)
		{
			//condition: point lies in given range
			if(points[pcount]>=segment[check][0] && points[pcount]<=segment[check][1])
			{
				counter++;
			}
		}
		cout << counter << " ";
	}
		
}

