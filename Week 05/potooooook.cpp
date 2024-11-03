#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// https://www.hackerrank.com/contests/si-practice-4/challenges/challenge-1645/problem

struct Node
{
    int data=0;
    Node* next=nullptr;
    
    Node(int data, Node* next = nullptr) : data(data), next(next)
    {
        
    }
};

int main() {
    
    Node* head=nullptr;
    Node* prev=nullptr;
    
    int num = 0;
    
    while(cin>>num)
    {
        Node* curr=new Node(num);
        
        if(!head)
        {
            head=curr;
            prev=curr;
        }
        else
        {
            prev->next=curr;
            prev=curr;
        }
    }
    
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    long long sum=0;
    
    Node* iter=head;
    
    while(iter)
    {
        int num=iter->data;
        sum+=num;
        minVal=min(minVal, num);
        maxVal=max(maxVal, num);
        iter=iter->next;
    }
    
    cout<<minVal<<' '<<maxVal<<' '<<sum;
    return 0;
}
