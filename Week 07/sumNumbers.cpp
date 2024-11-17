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

// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=problem-list-v2&envId=amgo332d

class Solution {
public:
    void dfs(TreeNode* curr,int& ans, int sum = 0)
    {
        if(!curr)
        {
           return;
        }

        sum*=10;
        sum+=curr->val;

         if(!curr->left && !curr->right)
        {
            ans+=sum;
            return;
        }

        dfs(curr->left,ans, sum);
        dfs(curr->right, ans, sum);
    }

    int sumNumbers(TreeNode* root) 
    {
        int ans=0;
        dfs(root, ans, 0);

        return ans;
        
    }
};
