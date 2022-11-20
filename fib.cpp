#include<iostream>
using namespace std;

int fibRec(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fibRec(n-1)+fibRec(n-2);
}

void fibIte(int n)
{
    int num1=0;
    int num2=1;
    int num3;
    cout<<num1<<" "<<num2<<" ";
    for(int i=2;i<n;i++)
    {
        num3=num1+num2;
        cout<<num3<<" ";
		
		num1=num2;
		num2=num3;
        
    }
}

int main()
{
    int n=5;
    cout<<"Recursive solution: ";
    for(int i=0;i<n;i++)
    {
        cout<<fibRec(i)<<" ";
    }
    cout<<endl;
    cout<<"Iterative solution: ";
    fibIte(n);
}