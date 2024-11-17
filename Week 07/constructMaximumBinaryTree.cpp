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

// https://leetcode.com/problems/maximum-binary-tree/description/?envType=problem-list-v2&envId=binary-tree

class Solution {
public:

    int findMaxIdx(const vector<int>& nums, int l , int r)
    {
        int maxIdx = l;

        for(int i = l; i < r; i++)
        {
            if(nums[maxIdx]<nums[i])
            {
                maxIdx=i;
            }
        }

        return maxIdx;
    }
    TreeNode* helper(vector<int>& nums, int l, int r)
    {
        if(l>=r)
        {
            return nullptr;
        }

        int maxIdx=findMaxIdx(nums,l,r);
        TreeNode* curr=new TreeNode(nums[maxIdx]);
        curr->left=helper(nums, l, maxIdx);
        curr->right=helper(nums, maxIdx+1, r);

        return curr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return helper(nums, 0, nums.size());
    }
};
