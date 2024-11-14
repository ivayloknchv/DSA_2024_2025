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

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=problem-list-v2&envId=tree

class Solution {
public:

    void addLeaves(TreeNode* curr, vector<int>& leaves)
    {
        if(!curr)
        {
            return;
        }
        if(!curr->left && !curr->right)
        {
            leaves.push_back(curr->val);
        }

        addLeaves(curr->left, leaves);
        addLeaves(curr->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leaves1;
        vector<int> leaves2;

        addLeaves(root1, leaves1);
        addLeaves(root2, leaves2);

        if(leaves1.size() != leaves2.size())
        {
            return false;
        }

        for(int i = 0; i < leaves1.size(); i++)
        {
            if(leaves1[i] != leaves2[i])
            {
                return false;
            }
        }

        return true;
    }
};
