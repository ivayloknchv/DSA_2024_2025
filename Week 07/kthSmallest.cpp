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

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/?envType=problem-list-v2&envId=binary-search-tree

class Solution 
{
public:

    void dfs(TreeNode* root, vector<int>& nums)
    {
        if(!root)
        {
            return;
        }

        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        if(!root)
        {
            return -1;
        }

        vector<int> nums;
        dfs(root, nums);

        return nums[k-1];
    }
};
