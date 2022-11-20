#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct MinheapNode
{
    char data;
    int freq;
    MinheapNode* left,*right;
    MinheapNode(char data,int freq)
    {
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};

//comparison
struct compare
{
    bool operator()(MinheapNode *l,MinheapNode *r)
    {
        return(l->freq>r->freq);
    }
};

void printcode(struct MinheapNode* root,string str)
{
    if(!root)
    {
        return;
    }
    if(root->data!='$')
    {
        cout<<root->data<<" : "<<str<<"\n";
    }
    printcode(root->left,str+'0');
    printcode(root->right,str+'1');
}

void Huffman(char data[],int freq[],int size)
{
    MinheapNode *left,*right,*top;
    priority_queue<MinheapNode*,vector<MinheapNode*>,compare> minHeap;

    for(int i=0;i<size;++i)
    {
        minHeap.push(new MinheapNode(data[i],freq[i]));
    }

    while(minHeap.size()!=1)
    {
        left=minHeap.top();
        minHeap.pop();

        right=minHeap.top();
        minHeap.pop();

        top=new MinheapNode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        minHeap.push(top);
    }
    printcode(minHeap.top(),"");
}

int main()
{
    char data[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};

    int size=sizeof(data)/sizeof(data[0]);
    Huffman(data,freq,size);
}