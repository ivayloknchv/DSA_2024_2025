/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:
    void binaryNumHelper(TreeNode* curr, vector<int>& res, int currentNum=0)
    {
        if(!curr)
        {
            return;
        }

        if(!curr->left && !curr->right)
        {
            currentNum*=2;
            currentNum+=curr->val;
            res.push_back(currentNum);
            return;
        }

        currentNum*=2;
        currentNum+=curr->val;
        
        binaryNumHelper(curr->left, res, currentNum);
        binaryNumHelper(curr->right, res, currentNum);
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        vector<int> res;

        long long sum = 0;

        binaryNumHelper(root, res);

        for(int n : res)
        {
            sum+=n;
        }

        return sum;
    }
};
