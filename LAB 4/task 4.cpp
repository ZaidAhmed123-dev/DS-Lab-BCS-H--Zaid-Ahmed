#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
		
	for(int i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = key;
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int BinarySearch(int arr[],int n, int key)
{
	int left = arr[0];
	int right = arr[n-1];
	
	while (left <= right) 
	{
	int mid = left + (right - left) / 2;
	if (arr[mid] == key) {
	return mid;
	}
	else if (arr[mid] < key) {
	left = mid + 1;
	}
	else {
	right = mid - 1;
	}
	}
	return -1;
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
	
	InsertionSort(arr,n);
	
	int k;
	cout<<"\nenter number to search for: ";
	cin>>k;
	
	if(BinarySearch(arr,n,k)!=-1)
	{
		cout<<"the index is: "<<BinarySearch(arr,n,k)<<endl;
	}
	else
		cout<<"number not found!\n";
}
