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

// https://leetcode.com/problems/increasing-order-search-tree/description/?envType=problem-list-v2&envId=aw7610t5

class Solution {
public:

    void dfs(TreeNode* root, vector<TreeNode*>& res)
    {
        if(!root)
        {
            return;
        }

        dfs(root->left,res);
        res.push_back(root);
        dfs(root->right, res);
    }

    TreeNode* increasingBST(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }
        vector<TreeNode*> vec;
        dfs(root, vec);
        TreeNode * ans=vec[0];
        ans->left=nullptr;
        ans->right=nullptr;

        TreeNode* prev=vec[0];

        for(int i = 1; i<vec.size(); i++)
        {
            vec[i]->left=nullptr;
            vec[i]->right=nullptr;
            prev->right=vec[i];
            prev=prev->right;
        }

        return ans;
    }
};
