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

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(!root)
        {
            return res;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int level = q.size();
            vector<int> currentLevel;

            for(int i = 0; i < level; i++)
            {
                TreeNode* curr= q.front();
                q.pop();

                if(curr)
                {
                    currentLevel.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(!currentLevel.empty())
            {
                res.push_back(currentLevel);
            }
        }
        return res;
    }
};
