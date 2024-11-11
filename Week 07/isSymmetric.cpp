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

// https://leetcode.com/problems/symmetric-tree/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:

    bool isSymmetricHelper(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            return true;
        }
        else if(!p || !q)
        {
            return false;
        }

        return (p->val == q->val) && isSymmetricHelper(p->left, q->right) &&
        isSymmetricHelper(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
       if(!root)
       {
            return true;
       }

       return isSymmetricHelper(root->left, root->right);
    }
};
