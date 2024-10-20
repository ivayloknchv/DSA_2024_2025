// https://leetcode.com/problems/count-of-smaller-numbers-after-self/?envType=problem-list-v2&envId=merge-sort&fbclid=IwZXh0bgNhZW0CMTEAAR3bcezJ2Y9PoHXDHuawWjzkmARQA_Xap_ohfCUmXLZY3qQTaqXjkVzlfP8_aem_D2tirFcxTOBzfuZ3AJWzaw

class Solution {
public:

    void merge(vector<pair<int,int>>& vec, int l, int m, int r, vector<int>& counts, vector<pair<int,int>>& buff)
    {
        int leftStart=l;
        int leftEnd=m;
        int rightStart=m+1;

        int idx=l;
        int rightCounter=0;

        while(leftStart<=leftEnd && rightStart<=r)
        {
            if(vec[leftStart].first<=vec[rightStart].first)
            {
                counts[vec[leftStart].second]+=rightCounter;
                buff[idx++]=vec[leftStart++];
            }

            else
            {
                rightCounter++;
                buff[idx++]=vec[rightStart++];
            }
        }

        while(leftStart<=leftEnd)
        {
            counts[vec[leftStart].second]+=rightCounter;
            buff[idx++]=vec[leftStart++];
        }

        while(rightStart<=r)
        {
            buff[idx++]=vec[rightStart++];
        }

        for(int i=l;i<=r;i++)
        {
            vec[i]=buff[i];
        }
    }

    void mergeAndCount(vector<pair<int,int>>& vec, int l, int r, vector<int>& counts, vector<pair<int,int>>& buff)
    {
        if(l<r)
        {
            int mid = l + (r-l)/2;

            mergeAndCount(vec, l, mid, counts, buff);
            mergeAndCount(vec, mid+1, r, counts, buff);
            merge(vec, l, mid, r, counts, buff);
        }
        else
        {
            return;
        }
    }

    vector<int> countSmaller(vector<int>& nums)
    {
        int n=nums.size();
        vector<pair<int,int>> vec(n);
        vector<int> counts(n);
        vector<pair<int,int>> buff(n);

        for(int i =0; i<n;i++)
        {
            vec[i]={nums[i], i};
        }

        mergeAndCount(vec,0,n-1,counts,buff);

        return counts;
    }
};
