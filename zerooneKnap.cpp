#include<bits/stdc++.h>
using namespace std;

int knapsack(int W,int wt[],int val[],int n)
{
    int i,w;
    vector<vector<int>> K(n+1,vector<int>(W+1));
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
            {
                K[i][w]=0;
            }
            else if(wt[i-1]<=w)
            {
                K[i][w]=max(K[i-1][w],val[i-1]+K[i-1][w-wt[i-1]]);
            }
            else{
                K[i][w]=K[i-1][w];
            }
        }
        
    }
    return K[n][W];
}

int main()
{
    int W=5;
    int val[]={20,30,10,50};
    int wt[]={1,3,4,6};
    int n=sizeof(val)/sizeof(val[0]);
    cout<<knapsack(W,wt,val,n);
}