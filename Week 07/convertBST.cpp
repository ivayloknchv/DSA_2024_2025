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

// https://leetcode.com/problems/convert-bst-to-greater-tree/description/

class Solution {
public:
    void dfs(TreeNode* curr, int& sum)
    {
        if(!curr)
        {
            return;
        }

        dfs(curr->right, sum);
        curr->val += sum;
        sum=curr->val;
        dfs(curr->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }
        int sum = 0;
        dfs(root,sum);
        return root;    
    }
};
