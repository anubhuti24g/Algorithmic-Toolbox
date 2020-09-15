#include <iostream>

using namespace std;

int moneyChangeCalc(int n, int noOfCoins)
{
	//case: no. is divisible by 4
	if(n%4==0)
	{
		//divide it by 4 and take quotient as noOfCoins
		noOfCoins+= n/4;
	}
	
	//case: no. is divisible by 3
	else if(n%3==0)
	{			
		//subcase: else (only divisible by 3, not by 12)
		if(n%12!=0)
		{
			//subtract 3 and check again
			n=n-3;
			noOfCoins++;
			noOfCoins = moneyChangeCalc(n,noOfCoins);
		}
	}
	
	//case: no. is neither divisible by 4 nor by 3
	else
	{	
		//if>4: subtract and call fn again
		if(n>4)
		{
			n=n-4;
			noOfCoins++;
			noOfCoins = moneyChangeCalc(n,noOfCoins);
		}
		//if<3: no. is noOfCoins
		else if(n<3)
		{
			noOfCoins+= n;
		}
	}
	return noOfCoins;
}

int main()
{
	int number;
	cin >> number;
	
	//define variable change to store noOfCoins
	int change=0;
	
	//pass number through money change function
	change = moneyChangeCalc(number,0);
	
	cout << change;
}

