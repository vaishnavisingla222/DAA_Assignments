#include<iostream>
using namespace std;
double maxValue(int total,int capacity,int value[],int weight[],double valPerMass[])
{
    if(capacity==0)
    return 0;

    double maxRatio=-1;
    int maxIndex=-1;
    for(int i=0;i<total;i++)
    {
        if(weight[i]>0 && valPerMass[i]>maxRatio)
        {
            maxRatio=valPerMass[i];
            maxIndex=i;
        }
    }
    if(maxIndex==-1) // no item left
    return 0;

    if(weight[maxIndex]<=capacity) // full item is taken
    {
        capacity-=weight[maxIndex];
        int priceTaken=value[maxIndex];
        value[maxIndex]=-1;
        weight[maxIndex]=0;
        valPerMass[maxIndex]=0;

        return priceTaken+maxValue(total,capacity,value,weight,valPerMass);
    }
    double part=(double)capacity/weight[maxIndex];// some part is taken
    return (double)value[maxIndex]*part;
}
int main()
{
    int total,capacity;
    cout<<"Enter the total number of items: ";
    cin>>total;
    int value[total],weight[total];
    double valPerMass[total];

    cout<<"Enter the value of each item: ";
    for(int i=0;i<total;i++)
    cin>>value[i];

    cout<<"Enter the weight of each item: ";
    for(int i=0;i<total;i++)
    cin>>weight[i];

    cout<<"Enter the total capacity possible: ";
    cin>>capacity;

    //value/weight ratio
    for(int i=0;i<total;i++)
    valPerMass[i]=(double)value[i]/(double)weight[i];

    double maxVal=maxValue(total,capacity,value,weight,valPerMass);
    cout<<"Maximum value: "<<maxVal;
}