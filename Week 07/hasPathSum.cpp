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

// https://leetcode.com/problems/path-sum/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:

    bool helperFunc(TreeNode* root, int curr, int target)
    {
        if(!root)
        {
            return false;
        }
        
        if(!root->left && !root->right)
        {
            return root->val+curr==target;
        }

        curr+=root->val;

        return helperFunc(root->left, curr, target) || helperFunc(root->right, curr, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
        {
            return false;
        } 
        return helperFunc(root, 0, targetSum);
    }
};
