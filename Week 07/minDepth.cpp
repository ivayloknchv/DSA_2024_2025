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

// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:

    int helperFunc(TreeNode* node, int curr)
    {

        if(!node->left && !node->right)
        {
            return curr;
        }

        int leftMin = !node->left ? INT_MAX : helperFunc(node->left, curr+1);
        int rightMin = !node->right ? INT_MAX : helperFunc(node->right, curr+1);
        return min(leftMin, rightMin);
    }
    int minDepth(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        return helperFunc(root, 1);
    }
};
