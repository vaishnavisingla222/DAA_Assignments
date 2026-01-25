#include<iostream>
using namespace std;
int partition(int arr[],int si,int ei)
{
    int pivot=arr[si];
    int count=0;
    
    for(int i=si+1;i<=ei;i++)
    {
        if(arr[i]<=pivot)
        count++;
    }

    int pivind=count+si;
    int temp=arr[si];
    arr[si]=arr[pivind];
    arr[pivind]=temp;

    int i=si,j=ei;
    while(i<pivind && j>pivind)
    {
        while(arr[i]<=pivot) 
        i++;

        while(arr[j]>pivot) 
        j--;

        if (i<pivind && j>pivind) 
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    return pivind;
}
void Quick_sort(int arr[],int si,int ei)
{
    if(si>ei)
    return;

    int pivot=partition(arr,si,ei);
    Quick_sort(arr,si,pivot-1);
    Quick_sort(arr,pivot+1,ei);
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

    Quick_sort(arr,0,size-1);

    cout<<"The sorted array: ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}