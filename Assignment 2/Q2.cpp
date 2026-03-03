#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int platform(int total,int start[],int end[])
{
    sort(start,start+total);
    sort(end,end+total);

    int current=1;
    int maxPlatform=1;
    int i=1;//start[0] is considered
    int j=0;//no departure is considered
    while(i<total && j<total)
    {
        if(start[i]<=end[j])
        {
            current++;
            i++;
            maxPlatform=max(maxPlatform,current);
        }
        else
        {
            current--;
            j++;
        }
    }
    return maxPlatform;
}

int main()
{
    int total;
    cout<<"Enter the total number of trains coming: ";
    cin>>total;
    int start[total],end[total];

    cout<<"Enter the arrival time in 24hrs format of each train in sequence: ";
    for(int i=0;i<total;i++)
    cin>>start[i];

    cout<<"Enter the departure time in 24hrs format of each train in sequence: ";
    for(int i=0;i<total;i++)
    cin>>end[i];

    int minPlatform=platform(total,start,end);
    cout<<"Minimum number of platforms needed: "<<minPlatform;
}