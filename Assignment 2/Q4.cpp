#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.second>b.second;
}

int maxProfit(int total,int deadline[],int profit[])
{
    vector <pair<int,int>> job;
    for(int i=0;i<total;i++)
    {
        pair<int,int> p=make_pair(deadline[i],profit[i]);
        job.push_back(p);
    }
    sort(job.begin(),job.end(),compare); // sort according to the job profit, maximum profit to be done first

    int maxDeadline=0;
    for(int i=0;i<total;i++)
    maxDeadline=max(job[i].first,maxDeadline);

    vector<int> slot(maxDeadline+1,-1); // to decide which job to be done in which slot
    int totalProfit=0;

    cout<<"Job done: ";
    for(int i=0;i<total;i++)
    {
        if(job[i].first==-1)
        continue;

        for(int d=job[i].first;d>0;d--) //deciding which slot will it use
        {
            if(slot[d]==-1)
            {
                job[i].first=-1;
                slot[d]=i;
                cout<<i+1<<" , ";
                totalProfit+=job[i].second;
                break;
            }
        }
    }
    return totalProfit;
}
int main()
{
    int total;
    cout<<"Enter the total number of jobs: ";
    cin>>total;
    int deadline[total],profit[total];

    cout<<"Enter the deadline of each job in sequence: ";
    for(int i=0;i<total;i++)
    cin>>deadline[i];

    cout<<"Enter the profit of each job in sequence: ";
    for(int i=0;i<total;i++)
    cin>>profit[i];

    int profitMade=maxProfit(total,deadline,profit);
    cout<<"\nMaximum Profit made: "<<profitMade;
}