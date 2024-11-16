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

//https://leetcode.com/problems/invert-binary-tree/?envType=problem-list-v2&envId=amgo332d

class Solution {
public:

    void reverse(TreeNode* curr)
    {
        if(!curr)
        {
            return;
        }

        swap(curr->left, curr->right);

        reverse(curr->left);
        reverse(curr->right);
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }    
        reverse(root);
        return root;
    }
};
