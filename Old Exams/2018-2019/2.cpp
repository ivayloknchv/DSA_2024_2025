#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
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
    
    Node* removeHelper(Node* curr, int X)
    {
        if(!curr)
        {
            return curr;
        }
        
        if(curr->val > X)
        {
            curr->left = removeHelper(curr->left, X);
        }
        else if(curr->val < X)
        {
            curr->right = removeHelper(curr->right, X);
        }
        else
        {
            if(!curr->left)
            {
                Node* tmp = curr->right;
                delete curr;
                return tmp;
            }
            if(!curr->right)
            {
                Node* tmp = curr->left;
                delete curr;
                return tmp;
            }
            
            Node* iter = curr->right;
            
            while(iter->left)
            {
                iter=iter->left;
            }
            
            curr->val = iter->val;
            curr->right = removeHelper(curr->right, iter->val);
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
    
    void print_odd_layers()
    {
        if(!root)
        {
            return;
        }
        
        int layer = 1;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int s = q.size();
            
            for(int i = 0; i < s; i++)
            {
                Node* curr = q.front();
                q.pop();
                
                if(layer%2==1)
                {
                    cout<<curr->val<<' ';
                }
                
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            
            layer++;
        }
    }
    
    void remove(int X)
    {
        this->root = removeHelper(this->root, X);
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
        else if(command == "print_odd_layers")
        {
            tree.print_odd_layers();
        }
        else if(command == "remove")
        {
            int x = 0;
            cin>>x;
            tree.remove(x);
        }
    }
    return 0;
}
