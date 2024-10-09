class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {        
        int size=nums.size();

        vector<int> freqNums=vector<int>(size);

        for(int i=0;i<size;i++)
        {
            freqNums[nums[i]-1]++;
        }

        int maxFreq=freqNums[0];

        for(int i=0;i<size;i++)
        {
            if(freqNums[i]>maxFreq)
            {
                maxFreq=freqNums[i];
            }
        }

        vector<vector<int>> ans=vector<vector<int>>(maxFreq);

        for(int i=0;i<size;i++)
        {
            int freq=freqNums[i];

            for(int j=0;j<freq;j++)
            {
                ans[j].push_back(i+1);
            }
        }

        return ans;
    }
};
