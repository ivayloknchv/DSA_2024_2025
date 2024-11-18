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

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=problem-list-v2&envId=binary-search-tree

class Solution {
public:
    TreeNode* helperFunc(const vector<int>& nums, int l, int r)
    {
        if(l>r)
        {
            return nullptr;
        }

        int mid = l + (r - l) / 2;

        TreeNode* curr=new TreeNode(nums[mid]);
        curr->left=helperFunc(nums, l, mid-1);
        curr->right=helperFunc(nums, mid+1, r);

        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return helperFunc(nums, 0, nums.size()-1);    
    }
};
