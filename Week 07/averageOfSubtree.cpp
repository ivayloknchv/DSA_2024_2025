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

// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/?envType=problem-list-v2&envId=amgo332d

class Solution 
{
public:
    void avgHelper(TreeNode* root, int& ans, int& sum, int& counter)
    {
        if(!root)
        {
            return;
        }


        int leftSum=0;
        int leftCount=0;   
        int rightSum=0;
        int rightCount=0;

        avgHelper(root->left, ans, leftSum, leftCount);
        avgHelper(root->right,ans, rightSum, rightCount);

        sum=root->val+leftSum+rightSum;
        counter=leftCount+rightCount+1;

        if(sum/counter== root->val)
        {
            ans++;
        }
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int counter=0;
        int sum = 0;
        int ans = 0;

        avgHelper(root, ans, sum, counter);

        return ans;
    }
};
