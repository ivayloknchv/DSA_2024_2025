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

// https://leetcode.com/problems/even-odd-tree/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty())
        {
            int levelSize=q.size();
            TreeNode* prev = nullptr;

            for(int i = 0; i <levelSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(level%2==0)
                {
                    if( curr->val%2==0 || (prev &&prev->val >= curr->val))
                    {
                        return false;
                    }
                }
                else
                {
                    if(curr->val %2!=0 || (prev && prev->val <= curr->val))
                    {
                        return false;
                    }
                }

                prev=curr;

                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            level++;
        }
        return true;
    }
};
