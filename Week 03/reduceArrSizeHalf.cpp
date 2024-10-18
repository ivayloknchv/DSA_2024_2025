// https://leetcode.com/problems/reduce-array-size-to-the-half/description/?envType=problem-list-v2&envId=awdef2cg

class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int count[100001]{};

        for(int i = 0; i<arr.size(); i++)
        {
            count[arr[i]]++;
        }    

        sort(count, count + 100001);

        int size=arr.size();
        int sum=0;
        int counter=0;
        
        for(int i = 100000; i>=0; i--)
        {
            if(count[i]!=0)
            {
                sum+=count[i];
                counter++;
            }

            if(sum>=size/2)
            {
                return counter;
            }
        }

        return 0;
    }
};
