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

// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class Solution {
public:

    void traversalHelper(TreeNode* curr, vector<int>& res)
    {
        if(!curr)
        {
            return;
        }

        traversalHelper(curr->left, res);
        res.push_back(curr->val);
        traversalHelper(curr->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;

        if(!root)
        {
            return res;
        }

        traversalHelper(root, res);

        return res;
    }
};
