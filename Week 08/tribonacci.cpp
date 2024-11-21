// https://leetcode.com/problems/n-th-tribonacci-number/description/

class Solution {
public:

    int tribonacci(int n, vector<int>& cache)
    {
        if(n==0)
        {
            return cache[0]=0;
        }
        else if(n==1)
        {
            return cache[1]=1;
        }
        else if(n==2)
        {
            return cache[2]=1;
        }
        else if(cache[n]!=-1)
        {
            return cache[n];
        }

        return cache[n] = tribonacci(n-3, cache) + tribonacci(n-2, cache) + tribonacci(n-1, cache);
    }

    int tribonacci(int n) 
    {
        vector<int> cache(n+1,-1);

        return tribonacci(n, cache);   
    }
};
