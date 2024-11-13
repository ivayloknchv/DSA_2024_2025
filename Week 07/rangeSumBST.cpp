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

// https://leetcode.com/problems/range-sum-of-bst/description/

class Solution 
{
public:

    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(!root)
        {
            return 0;
        }

        int num = 0;

        if(low<=root->val && root->val <=high)
        {
            num = root->val;
        }

        return num + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
