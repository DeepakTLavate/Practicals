#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value,weight;
    Item(int value,int weight)
    {
        this->value=value;
        this->weight=weight;
    }
};

bool compare(struct Item a,struct Item b)
{
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;

}

double FracKnapsack(int W,struct Item arr[],int N)
{
    sort(arr,arr+N,compare);

    double finalVal=0.0;

    for(int i=0;i<N;i++)
    {
        if(arr[i].weight<=W)
        {
            finalVal+=arr[i].value;
            W-=arr[i].weight;
        }
        else
        {
            finalVal+=arr[i].value*((double)W/(double)arr[i].weight);
            break;
        }
    }

    return finalVal;
}

int main()
{
    int W=40;
    Item arr[]={{30,5},{40,10},{45,15},{77,22},{90,25}};
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum value that we can obtain : "<<FracKnapsack(W,arr,N);
}