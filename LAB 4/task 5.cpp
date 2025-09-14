#include<iostream>
using namespace std;

int InterpolationSearch(int arr[],int n, int k)
{
	int low =0;
	int high= n-1;
	
	while(low <= high && k>= arr[low] && k <= arr[high])
	{
		if(low==high){
			if(arr[low] == k)
			return low;
			
			return -1;
		}
		
		int pos = low+((k-arr[low]) * (high - low)) / (arr[high] - arr[low]);
		
		if(arr[pos] == k)
		return pos;
		
		if(arr[pos] < k)
		low = pos+1;
		
		else 
		high = pos-1;
	}
	
	return -1;
}



int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n= sizeof (arr) / sizeof(arr[0]);
		
	int k;
	cout<<"\nenter number to search for: ";
	cin>>k;
	
	if(InterpolationSearch(arr,n,k)!=-1)
	{
		cout<<"the index is: "<<InterpolationSearch(arr,n,k) <<endl;
	}
	else
		cout<<"number not found!\n";
}
