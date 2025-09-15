#include <iostream>
using namespace std;

int calculateFactorial(int n)
{
	if(n<=0)
	return 1;
	
	return n*calculateFactorial(n-1);
}

int main()
{
	int n;
	cout<<"enter a number to calcuylate factorial for: ";
	cin>>n;
	
	cout<<"factorial is: "<<calculateFactorial(n)<<endl;
}
