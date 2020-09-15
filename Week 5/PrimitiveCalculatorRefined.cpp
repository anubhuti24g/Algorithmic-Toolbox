#include <iostream>
#include <vector>

using namespace std;

void storeSteps(long iArray[ ][2], vector<long> & oArray, long m, long nSt)
{
long in = 0;
while(in<nSt)
{
	if(m!=1)
	{
		if(m%3==0)
		{
			if(iArray[m-2][1]<=iArray[(m/3)-1][1])
			{
				oArray.at(in) = iArray[m-2][0];
				m=m-1;
			}
			else
			{
				oArray.at(in) = iArray[(m/3)-1][0];
				m=m/3;
			}
		}
		else if(m%2==0)
		{
			if(iArray[m-2][1]<=iArray[(m/2)-1][1])
			{
				oArray.at(in) = iArray[m-2][0];
				m=m-1;
			}
			else
			{
				oArray.at(in) = iArray[(m/2)-1][0];
				m=m/2;
			}
		}
		//case:not divisible by either
		else
		{
			oArray.at(in) = iArray[m-2][0];
			m=m-1;
		}
		in++;
	}
}
}

void stepCalc(long array[ ][2],long i)
{
	//check if number is divisible by 3 or 2
	if(i%3==0)
	{
		//case:yes
		//check steps of divided result
		//min(steps of divided result, steps of number-1)
		//store steps + 1 for that number
		array[i-1][1] = min(array[i-2][1],array[(i/3)-1][1]) + 1;
	}
	else if(i%2==0)
	{
		//case:yes
		//check steps of divided result
		//min(steps of divided result, steps of number-1)
		//store steps + 1 for that number
		array[i-1][1] = min(array[i-2][1],array[(i/2)-1][1]) + 1;
	}
	//case:not divisible by either
	else
	{
		//add 1 to previous no. steps
		array[i-1][1] = array[i-2][1] + 1;
	}
}

int main()
{
	//take input n
	long n = 0;
	cin >> n;
	
	//create array of size n*2
	long inputArray[n][2];
	
	//store 1st 3 elements {(1,0);(2,1);(3,1)}
	inputArray[0][0] = 1;
	inputArray[0][1] = 0;
	inputArray[1][0] = 2;
	inputArray[1][1] = 1;
	inputArray[2][0] = 3;
	inputArray[2][1] = 1;
	
	//pass array, and number to be checked through a function
	for(long k=4;k<n+1;k++)
	{
		inputArray[k-1][0] = k;
		stepCalc(inputArray, k);
	}
	
	long nSteps = inputArray[n-1][1];
	
	cout << nSteps <<endl;
	
if(nSteps!=0)
{
	//create array to store all steps of reaching n
	//long stepsArray[nSteps];
	
	//create vector to store all steps of reaching n
	vector<long> stepsArr(nSteps);
	
	//store Steps
	storeSteps(inputArray, stepsArr, n, nSteps);
	
	for(long f=nSteps-1;f>=0;f--)
		cout << stepsArr.at(f) << " ";
}
		
	cout << n;
}

