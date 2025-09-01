#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"enter the size of the array : ";
	cin>>n;
	
	int *arr = new int[n];
	
	for(int i=0;i < n; i++)
	{
		arr[i]=0;
	}
	
	int pos,val;
	for(int i=0; i<n;i++)
	{
		cout<<"enter a position and the value for that position (or press 0 to exit): ";
		cin>>pos;
		if(pos==0)
		break;
		cin>>val;
		
		arr[pos-1]=val;
	}
	
	cout<<"array: ";
	for(int i=0;i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	delete[] arr;
	
	
}
