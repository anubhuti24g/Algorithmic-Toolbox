#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//user inputs the number required
	long n=0;
	cin >> n;
	long m=n;
	
	//define a counter to count maximum numbers needed
	int counter=0;
	
	//run a loop starting from 1, while number!=0
	vector<long> numbers;
	int i=1;
	int diff=0;
	
	while(m!=0)
	{
		diff=m-i;
		
		//keep assigning no.s in increasing order 1,2,3 and so on to an array and subtracting their sum from the target number
		if(diff>=0)
		{
			m=m-i;
			counter++;
			numbers.push_back(i);
		}
		
		//when no. to be subtracted is less than number left, then remove remainder from array, and add current number
		else
		{
			m=0;
			for(int k=(-1*diff)-1;k<counter-1;k++)
			{
				numbers.at(k)=numbers.at(k+1);
			}
			numbers.at(counter-1) = i;
		}
		i++;
		//cout << "diff: " << diff <<  endl;
		//cout << "n: " << n << endl;
	}
	
	//print counter and digits
	cout << counter << endl;
	for (long x : numbers) 
        cout << x << " ";
}

