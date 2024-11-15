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

// https://leetcode.com/problems/univalued-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:
    bool dfs(TreeNode* curr, int val)
    {
        if(!curr)
        {
            return true;
        }

        return curr->val == val && dfs(curr->left, val) && dfs(curr->right, val);
    }

    bool isUnivalTree(TreeNode* root)
    {
        if(!root)
        {
            return true;
        }

        return dfs(root, root->val);
    }
};
