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

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:

    int maxDepth(TreeNode* p, int counter)
    {
        if(!p)
        {
            return counter;
        }

        return max(max(counter,maxDepth(p->left, counter + 1)), maxDepth(p->right, counter + 1));
    }
    int maxDepth(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }

        int counter=0;
        int ans=maxDepth(root, counter);

        return ans;   
    }
};
