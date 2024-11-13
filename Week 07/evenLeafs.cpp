#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/contests/sda-2021-2021-test-3-november16/challenges/challenge-1692

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }

    int sum(Node* curr)
    {
        if(!curr)
        {
            return 0;
        }
        if(!curr->leftNode && !curr->rightNode)
        {
            if(curr->data % 2 == 1)
            {
                return curr->data;
            }
            else
            {
                return 0;
            }
        }
        
        return sum(curr->leftNode) + sum(curr->rightNode);
    }
	void leaves(Node *root) 
    { 
        if(!root)
        {
            std::cout<<0<<'\n';
            return;
        }
        
        std::cout<<sum(root)<<'\n';     
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leaves(root);
    return 0;
}
