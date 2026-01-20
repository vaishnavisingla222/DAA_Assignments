#include<iostream>
using namespace std;
int binarySearch(int arr[],int target,int st,int end)
{
    if(st>end)
    return -1;

    int mid=st+(end-st)/2;
    if(arr[mid]==target)
    return mid;

    else if(arr[mid]<target)
    return binarySearch(arr,target,mid+1,end);

    else
    return binarySearch(arr,target,st,mid);
}
int main()
{
    int size,target;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the ellements of the array: ";
    for(int i=0;i<size;i++)
    cin>>arr[i];

    cout<<"Enter the targeted ellemnt: ";
    cin>>target;

    int pos=binarySearch(arr,target,0,size-1);
    cout<<"Ellement found at position: "<<pos<<endl;
}
