#include<cmath>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long int n;
	cin>>n;
	long int sum=0;
	long int temp=0;
	long int y= (1+ sqrt(1+4*n))/2;
	long int x= sqrt(y);
	for(long int i=1;i<=x;i++)
	{
	    temp+=n/i;
	}

	temp = 2*temp-x*x;
	sum= temp+y- (y*(1+y))/2;
	cout<<sum<<endl;
	return 0;
}

