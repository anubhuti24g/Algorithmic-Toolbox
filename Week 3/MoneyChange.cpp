#include <iostream>

using namespace std;

int MoneyChange(int money)
{
	int tens = money/10;
	int fives = (money%10)/5;
	int ones = (money%5);
	int total = tens+fives+ones;
	
	return total;
}

int main()
{
	int n=0;
	cin >> n;
	cout << MoneyChange(n);
}
