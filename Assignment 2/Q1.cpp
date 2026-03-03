#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

int activitySelection(int total,int start[],int end[])
{
    //sort the activities according to their ending time
    vector <pair<int,int>> activity;
    for(int i=0;i<total;i++)
    {
        pair<int,int> p=make_pair(start[i],end[i]);
        activity.push_back(p);
    }
    sort(activity.begin(),activity.end(),compare);

    int count=1;//first meeting is taken
    cout<<"1 , ";
    int endTime=activity[0].second;
    for(int i=1;i<total;i++)
    {
        if(activity[i].first > endTime)
        {
            count++;
            endTime=activity[i].second;  
            cout<<i+1<<" , ";          
        }
    }
    return count;
}

int main()
{
    int total;
    cout<<"Enter the total number of activities present: ";
    cin>>total;
    int start[total],end[total];

    cout<<"Enter the start time of each activity in sequence: ";
    for(int i=0;i<total;i++)
    cin>>start[i];

    cout<<"Enter the end time of each activity in sequence: ";
    for(int i=0;i<total;i++)
    cin>>end[i];

    cout<<"The meetings which took place: ";
    int maxActivity=activitySelection(total,start,end);
    cout<<"\nMaximum number of activities can be performed: "<<maxActivity;
}
