#include <iostream>
#include <vector>

using namespace std;

int minOf(int a, int b, int c)
{
	if(a<=b && a<=c)
		return a;
	else if(b<=a && b<=c)
		return b;
	else
		return c;
}

//fn: calcED
void calcEd(vector<vector<int> > & matrix, int rows, int cols, char nElement, char mElement)
{
	//define in-del, match and mismatch
	int insertion = matrix[rows][cols-1] + 1;
	int deletion = matrix[rows-1][cols] + 1;
	int mismatch = matrix[rows-1][cols-1] + 1;
	int match = matrix[rows-1][cols-1];
	//to fill element mat(i,j)
	if(nElement==mElement)
	{
		//min of: insertion, deletion and match
		matrix[rows][cols] = minOf(insertion,deletion,match);
	}
	else
	{
		//min of: insertion, deletion and mismatch
		matrix[rows][cols] = minOf(insertion,deletion,mismatch);
	}
	
	//if min are vertical and horizontal paths then let it be
	//add 1 to previous
	
	//if diagonal path, then check whether str1[i-1]==str2[j-1]
	//yes: match
	//don't add 1
	
	//no: mismatch
	//add 1
}

int main()
{
	//define 2 strings of max size 100
	char str1[100], str2[100];
	
	//take input values of strings
	cin >> str1 >> str2;
	
	//declare variable to store size of string 1
	int nSize1=0;
	while(str1[nSize1]!='\0')
	{
		//calc size of str1
		nSize1++;
	}
	
	//declare variable to store size of string 2
	int mSize2=0;
	while(str2[mSize2]!='\0')
	{
		//calc size of str2
		mSize2++;
	}
	
	// Create a vector containing n 
    //vectors of size m.  
    vector<vector<int> > nmMatrix( (nSize1+1) , vector<int> (mSize2+1));
	
	//fill in the 1st column with values 0...n
	for(int i=0;i<=nSize1;i++)
		nmMatrix[i][0] = i;
	
	//fill in the 1st row with values 0...m
	for(int i=0;i<=mSize2;i++)
		nmMatrix[0][i] = i;
		
	//pass each unit of the matrix through a loop
	//ext loop: j: 1 to m+1
	for(int j=1;j<=mSize2;j++)
	{
		//int loop: i: 1 to n+1
		for(int i=1;i<=nSize1;i++)
		{
			//to calculate edit distance of that element, pass through fn, calcED
			calcEd(nmMatrix, i, j, str1[i-1], str2[j-1]);
		}
	}
	
	cout << nmMatrix[nSize1][mSize2];
	//output matrix to check if values have been stored correctly
	/*
    for (int i = 0; i <=nSize1; i++)
	{ 
        for (int j = 0; j <=mSize2; j++)
		{ 
            cout<< nmMatrix[i][j]<< " "; 
        } 
        cout<< "\n"; 
    } 
	*/
	
	//random couts to check if char works or not
	/*
	cout << endl << str1 << endl << nSize1 << endl << str2 << endl << mSize2 << endl;
	cout << str1[3] << " " << str2[2];
	if(str1[2]==str2[2])
		cout << endl << "pass";
	else
		cout << endl << "fail";
	*/
	
	
}

