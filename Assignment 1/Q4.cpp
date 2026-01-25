#include<iostream>
#include <climits>
using namespace std;
int subarray(int arr[],int size)
{
    int max=INT_MIN;
    int sum=0;
    for(int i=1;i<size;i++)
    {
        sum+=arr[i];
        if(sum>max)
        max=sum;

        if(sum<0)
        sum=0;
    }
    return max;
}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the ellements of the array: ";
    for(int i=0;i<size;i++)
    cin>>arr[i];

    int sum=subarray(arr,size);
    cout<<"Largest subarray sum: "<<sum;
}