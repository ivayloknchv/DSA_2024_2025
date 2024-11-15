#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-2020-2021-test6-dbr8t-r/challenges/traversal-level-order/problem

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() 
    {
        if(!root)
        {
            return;
        }
        
        queue<Node*> q;
        Node* iter = root;
        q.push(iter);
        
        int currLevel=0;
        bool isReversed=false;
        
        while(!q.empty())
        {
            size_t levelSize=q.size();
            vector<int> vec;
            
            for(size_t i = 0; i < levelSize; i++)
            {
                Node* curr = q.front();
                q.pop();
                
                vec.push_back(curr->value);
                
                
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            
            if(currLevel%2==0)
            {
                for(size_t i  = 0; i <vec.size(); i++)
                {
                    cout<<vec[i]<<' ';
                }
            }
            else
            {
                int size=vec.size();
                
                for(int i =  size-1; i>=0; i--)
                {
                    cout<<vec[i]<<' ';
                }
            }
            currLevel++;
        }
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
  
    tree.printSFB();
    return 0;
}
