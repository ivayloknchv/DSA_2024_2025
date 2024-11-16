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

// https://leetcode.com/problems/path-sum-ii/description/?envType=problem-list-v2&envId=aw7610t5

class Solution {
public:

    void dfs(TreeNode* curr, vector<vector<int>>& ans, vector<int>& path, int sum, int target)
    {
        if(!curr)
        {
            return;
        }

        sum+=curr->val;
        path.push_back(curr->val);

        if(!curr->left && !curr->right && sum==target)
        {
             ans.push_back(path);
        }

        dfs(curr->left, ans, path, sum, target);
        dfs(curr->right, ans, path, sum, target);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;

        if(!root)
        {
            return ans;
        }
        vector<int> path;

        dfs(root, ans,path, 0, targetSum);

        return ans;
    }
};
