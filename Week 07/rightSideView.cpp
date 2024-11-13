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

// https://leetcode.com/problems/binary-tree-right-side-view/description/

class Solution {
public:

    void helperFunc(TreeNode* node, vector<int>& vec)
    {
        if(!node)
        {
            return;
        }

        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty())
        {
            int currLevel=q.size();

            for(int i = 0; i < currLevel; i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                
                if(i == currLevel-1)
                {
                    vec.push_back(curr->val);
                }


                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if(!root)
        {
            return res;
        }

        helperFunc(root, res);

        return res;
    }
};
