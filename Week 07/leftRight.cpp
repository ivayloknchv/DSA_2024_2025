#include <bits/stdc++.h>

// https://www.hackerrank.com/contests/test4-sda-/challenges/left-right-2/problem

using namespace std;

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

    void leftRightHelper(Node* root, int& l, int& r)
    {
        if(!root)
        {
            return;
        }
        
        if(root->leftNode)
        {
           leftRightHelper(root->leftNode, ++l, r);
        }
        if(root->rightNode)
        {
           leftRightHelper(root->rightNode, l, ++r);
        }
    }
	void leftRight(Node *root) {
        int l =0;
        int r =0;
        
        leftRightHelper(root, l, r);
        
        std::cout<<"["<<l<<","<<r<<"]";
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
  
	myTree.leftRight(root);
    return 0;
}
