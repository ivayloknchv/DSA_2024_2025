// https://leetcode.com/problems/majority-element-ii/description/?envType=problem-list-v2&envId=sorting&fbclid=IwZXh0bgNhZW0CMTEAAR19_Skn13jcEoBhB5s1JusitocqfP86tkPeES_tphTnB3R0IW0eZPNJDGM_aem_t5qpq2BKazoTVmcq2pTgOQ

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int reps=n/3;
        vector<int> res;
        sort(nums.begin(), nums.end());

        int idx=0;
        while(idx<n)
        {
            int current=nums[idx];
            int counter=0;

            while(idx<n)
            {
                if(current==nums[idx])
                {
                    counter++;
                    idx++;
                }
                else
                {
                    break;
                }
            }

            if(counter>reps)
            {
                res.push_back(current);
            }
        }

        return res;
    }
};



/* class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
    int reps = n / 3;
    vector<int> res;
    sort(nums.begin(), nums.end());

    int current = nums[0];
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == current)
        {
            counter++;
        }
        else
        {
            if (counter > reps)
            {
                res.push_back(current);
            }
            counter = 1;
            current = nums[i];
        }
    }

    if (counter > reps)
    {
        res.push_back(current);
    }

    return res;
    }
}; */
