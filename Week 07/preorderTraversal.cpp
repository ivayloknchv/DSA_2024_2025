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

// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution 
{
public:

    void traversalHelper(TreeNode* curr, vector<int>& vec)
    {
        if(!curr)
        {
            return;
        }

        vec.push_back(curr->val);
        traversalHelper(curr->left, vec);
        traversalHelper(curr->right, vec);   
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;

        traversalHelper(root, res);

        return res;
    }
};
