#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

// https://www.hackerrank.com/contests/sda-hw-6-2023/challenges/task3score/problem

using namespace std;

struct Node
{
    long long val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int val, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right)
    {
    }
};

long long getNodesCount(Node* curr)
{
    if(!curr)
    {
        return 0;
    }
    
    return 1 + getNodesCount(curr->left) + getNodesCount(curr->right);
}


Node* arr[10000001]{};

int main() 
{
    long long N=0;
    cin>>N;
    
    for(long long i = 0; i < N; i++)
    {
        long long l=0, r=0;
        cin>>l>>r;
        
        if(!arr[i])
        {
            arr[i]=new Node(i);
        }
        
        if(l!=-1)
        {
            if(!arr[l])
            {
                arr[l]=new Node(l);
            }
            arr[i]->left=arr[l];
        }
        
        if(r!=-1)
        {
            if(!arr[r])
            {
                arr[r]=new Node(r);
            }
            arr[i]->right=arr[r];
        }                
    }
    
    long long maxProduct=0;
    
    for(long long i = 0; i < N; i++)
    {
        long long l = getNodesCount(arr[i]->left);
        long long r = getNodesCount(arr[i]->right);
        long long m = N - l - r - 1;
        
        if(l == 0)
        {
            l=1;
        }
        if(r==0)
        {
            r=1;
        }
        if(m==0)
        {
            m=1;
        }
        long long p=l*m*r;
        maxProduct=max(maxProduct, p);
    }
    
    cout<<maxProduct;
    
    return 0;
}
