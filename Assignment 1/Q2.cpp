#include<iostream>
using namespace std;
void conqueor(int arr[],int si,int mid,int ei)
{
    int ls=mid-si+1;
    int rs=ei-mid;
    int left[ls];
    int right[rs];

    for(int i=0;i<ls;i++)
    left[i]=arr[i+si];

    for(int j=0;j<rs;j++)
    right[j]=arr[mid+1+j];

    int i=0,j=0,k=si;
    while(i<ls && j<rs)
    {
        if(left[i]<right[j])
        arr[k++]=left[i++];

        else
        arr[k++]=right[j++];
    }

    while(i<ls)
    arr[k++]=left[i++];

    while(j<rs)
    arr[k++]=right[j++];

    return;
}
void divide(int arr[],int si,int ei)
{
    if(si>=ei)
    return;

    int mid=si+(ei-si)/2;
    divide(arr,si,mid);
    divide(arr,mid+1,ei);
    conqueor(arr,si,mid,ei);
    return;  
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

    divide(arr,0,size-1);

    cout<<"The sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}