#include<iostream>
using namespace std;

void combSort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;
    int comps = 0, swaps = 0;

    while(gap > 1 || swapped)
    {
        gap = (gap*10)/13;
        if(gap < 1) gap = 1;

        swapped = false;
        for(int i=0;i+gap<n;i++)
        {
            comps++;
            if(arr[i] > arr[i+gap])
            {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\nComparisons: "<<comps<<"\nSwaps: "<<swaps<<endl;
}

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    combSort(arr,n);
}
