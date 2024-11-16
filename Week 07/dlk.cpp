#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/contests/test4-sda-/challenges/challenge-1691/problem

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
    
    void printHelper(Node* root, vector<int>& ans)
    {
        if(!root)
        {
            return;
        }
        
        printHelper(root->rightNode, ans);
        printHelper(root->leftNode, ans);
        ans.push_back(root->data);
    }

	void print(Node *root) 
    {
        vector<int> ans;
        printHelper(root, ans);
        
        for(size_t i  = 0; i< ans.size(); i++)
        {
            std::cout<<ans[i];
            
            if(i+1 != ans.size())
            {
                std::cout<<';';
            }
        }
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
  
	myTree.print(root);
    return 0;
}
