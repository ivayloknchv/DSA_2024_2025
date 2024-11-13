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

// https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
public:
    
    bool isValidHelper(TreeNode* curr, long long min, long long max)
    {
        if(!curr)
        {
            return true;
        }

        if(min<curr->val && curr->val<max)
        {
            return isValidHelper(curr->left, min, curr->val)
            && isValidHelper(curr->right, curr->val, max);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) 
    {
        return isValidHelper(root, LLONG_MIN, LLONG_MAX);
    }
};
