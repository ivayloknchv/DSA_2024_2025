#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

// https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/challenge-3757/problem

struct Node
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int val, Node* left=nullptr, Node* right=nullptr) : val(val), left(left), right(right)
    {}
};

Node* insert(Node* root, int val)
{
    if(!root)
    {
        return new Node(val);
    }
    
    if(root->val < val)
    {
        root -> right = insert(root->right, val);
    }
    else if(root->val > val)
    {
        root->left = insert(root->left, val);
    }
    
    return root;
}

void bfs(Node* root, map<int,int>& m)
{
    if(!root)
    {
        return;
    }
    
   queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty())
    {
        Node* node = q.front().first;
        int pos=q.front().second;
        q.pop();
        
        if(m.find(pos)==m.end())
        {
            m[pos]=node->val;
        }
        
        if(node->left)
        {
            q.push({node->left, pos-1});
        }
        if(node->right)
        {
            q.push({node->right, pos+1});
        }
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T  = 0;
    cin>>T;
    
    while(T--)
    {
        int N = 0;
        cin>>N;
        Node* root = nullptr;
        
        for(int i = 0; i < N; i++)
        {
            int num = 0;
            cin>>num;
            
            root=insert(root, num);
        }
        
        map<int, int> m;
        bfs(root, m);
        
        for(auto v : m)
        {
            cout<<v.second<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
