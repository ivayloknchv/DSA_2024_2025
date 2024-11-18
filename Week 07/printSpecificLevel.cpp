#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// https://www.hackerrank.com/contests/sda-2019-2020-test3/challenges/print-specific-level/problem

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

    void printSFB(int k) 
    {
       vector<int> ans;
       
        int currLevel = 0;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                Node* curr=q.front();
                q.pop();
                
                if(currLevel == k)
                {
                    ans.push_back(curr->value);
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
            
            if(currLevel==k)
            {
                break;
            }
            
            currLevel++;
        }
        
        reverse(ans.begin(), ans.end());
        
        for(int i : ans)
        {
            cout<< i <<' ';
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
 
    int k = 0;
    cin>>k;
    tree.printSFB(k);
    return 0;
}
