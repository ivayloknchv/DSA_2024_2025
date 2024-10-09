
//https://leetcode.com/problems/find-if-digit-game-can-be-won/description/?fbclid=IwZXh0bgNhZW0CMTEAAR2frYNiP2UGW6LLqOUUFL9effg55voQ27W4UXtPogbOiKjiKgMR5o48wK4_aem_Xh4wbNaKuqu2mlx5yXh6fA

class Solution {
public:
    bool canAliceWin(vector<int>& nums) 
    {
        int singleSum=0;
        int doubleSum=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=9)
            {
                singleSum+=nums[i];
            }
            else
            {
                doubleSum+=nums[i];
            }
        }   

        return singleSum!=doubleSum;
    }
};
