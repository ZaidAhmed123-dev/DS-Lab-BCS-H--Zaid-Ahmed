#include<iostream>
using namespace std;

void linearSearch(int arr[], int n, int key)
{
		
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			cout<<"the number is at index: "<<i<<endl;
			return;
		}
	}
	cout<<"number wasnt found!";
}



int main()
{
	int n;
	cout<<"enter the length of the array: ";
	cin>>n;
	
	int arr[n];
	
	cout<<"fill in the array with elements: ";
	
	for(int i =0; i<n;i++)
	{
		cin>>arr[i];
	}
	
	int k;
	cout<<"enter number to search for: ";
	cin>>k;

	linearSearch(arr,n,k);
	
	
}
