#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val = 0;
    Node* left=nullptr;
    Node* right=nullptr;
};


int paint(Node* curr, int& paints)
{
    if(!curr)
    {
        return -1;
    }
    
    if(!curr->left && !curr->right)
    {
        return 2;
    }
    
    int l = paint(curr->left, paints);
    int r = paint(curr->right, paints);
    
    if(l == 2 || r == 2)
    {
        paints++;
        return 0;
    }
    
    if(l == 0 || r == 0)
    {
        return 1;
    }
    
    return 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    cin>>N;
    
    vector<Node*> tree(N);
    
    for(int i = 0; i < N; i++)
    {
        tree[i] = new Node();
        tree[i]->val = i;
    }
    
    for(int i = 0; i < N; i++)
    {
        int l = 0, r = 0;
        cin>>l>>r;
        
        
        if(l!=-1)
        {
            tree[i]->left=tree[l];
        }
        
        if(r!=-1)
        {
            tree[i]->right=tree[r];
        }
    }
    
    int paints = 0;
    
    int rootState = paint(tree[0], paints);
    
    cout<<paints + (rootState == 2);
    
    return 0;
}
