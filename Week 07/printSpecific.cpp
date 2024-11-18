#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/--149/problem

struct Node 
{
    int val;
    Node* left;
    Node* right;
    
    Node(int val, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right)
    {}
};

Node* insert(Node* root, int val)
{
    if(!root)
    {
        return new Node(val);
    }
    
    if(root->val > val)
    {
        root->left = insert(root->left, val);
    }
    else if(root->val < val)
    {
        root->right = insert(root->right, val);
    }
    
    return root;
}

void dfs(Node* root)
{
    if(!root)
    {
        return;
    }
    
    if(root->left && root->right)
    {
        cout<<root->val<<' ';
    }
    
    dfs(root->left);
    dfs(root->right);
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 0;
    cin>>T;
    
    while(T--)
    {
        int N  = 0, num = 0;
        cin>>N>>num;
        Node* root = new Node(num);
        
        for(int i = 0; i < N-1; i++)
        {
            cin>>num;
            root=insert(root, num);
        }
        
        dfs(root);
        cout<<'\n';
            
    }
    return 0;
}
