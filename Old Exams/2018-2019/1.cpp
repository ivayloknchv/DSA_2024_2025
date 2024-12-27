#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(int val, Node* left = nullptr, Node* right=nullptr) : val(val), left(left), right(right)
    {}
};

class BST
{
    Node* root = nullptr;
    
    
    void printHelper(Node* curr)
    {
        if(!curr)
        {
            return;
        }
        cout<<curr->val<<' ';
        
        printHelper(curr->left);
        printHelper(curr->right);
    }
    
    Node* addHelper(Node* curr, int X)
    {
        if(!curr)
        {
            return new Node(X);
        }
        
        if(curr->val == X)
        {
            return curr;
        }
        
        if(curr->val < X)
        {
            curr->right = addHelper(curr->right, X);
        }
        
        else
        {
            curr->left = addHelper(curr->left, X);
        }
        
        return curr;
    }
    
    public:
    
    BST() = default;
    
    BST(Node* root) : root(root)
    {
        
    }
    
    void print()
    {
        printHelper(this->root);
    }
    
    void add(int X)
    {
        this->root=addHelper(this->root, X);
    }
};

int main() {
    BST tree;
    int N = 0;
    cin>>N;
    
    for(int i = 0; i < N; i++)
    {
        string command;
        cin>>command;
        
        if(command == "add")
        {
            int x = 0;
            cin>>x;
            tree.add(x);
        }
        else if(command=="print")
        {
            tree.print();
        }
    }
    return 0;
}
