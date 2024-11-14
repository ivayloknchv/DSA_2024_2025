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

// https://leetcode.com/problems/sum-of-left-leaves/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:

    int helperSum(TreeNode* curr, bool isLeft)
    {
        if(!curr)
        {
            return 0;
        }
        if(!curr->left && !curr->right)
        {
            if(isLeft)
            {
                return curr->val;
            }
        }

        return helperSum(curr->left, true) + helperSum(curr->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }

       return helperSum(root, false);
    }
};
