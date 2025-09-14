#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
		
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+i]=temp;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
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
	
	cout<<"unsorted array: \n";
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<"\n\nsorted array: \n";
	
	BubbleSort(arr,n);
	
}
