#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
		
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_index])
				min_index=j;
		}

			
		int temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
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
	
	SelectionSort(arr,n);
	
}
