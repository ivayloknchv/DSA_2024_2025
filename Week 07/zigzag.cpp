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

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=problem-list-v2&envId=aw7610t5

class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(!root)
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        int counter=0;

        while(!q.empty())
        {
            int levelSize=q.size();
            vector<int> l;

            for(int i = 0; i<levelSize; i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                l.push_back(curr->val);

                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }

            if(counter%2==1)
            {
                reverse(l.begin(), l.end());
            }
            ans.push_back(l);
            counter++;
        }

        return ans;
    }
};
