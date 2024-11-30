// https://leetcode.com/problems/degree-of-an-array/description/?envType=problem-list-v2&envId=hash-table

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, int> freqMap;
        unordered_map<int, pair<int,int>> firstLastMap;

        for(int i = 0; i < nums.size(); i++)
        {
            freqMap[nums[i]]++;

            if(firstLastMap.find(nums[i])==firstLastMap.end())
            {
                firstLastMap[nums[i]] = {i,i};
            }
            else
            {
                 firstLastMap[nums[i]].second=i;
            }
        }

        int maxFreq=0;
        int minDist=INT_MAX;

        for(auto& curr : freqMap)
        {
            int currNum=curr.first;
            int currFreq=curr.second;

            int currDist=firstLastMap[currNum].second - firstLastMap[currNum].first + 1;

            if(maxFreq<currFreq)
            {
                maxFreq=currFreq;
                minDist=currDist;
            }
            if(maxFreq==currFreq)
            {
                minDist=min(minDist, currDist);
            }
        }

        return minDist;
    }
};
