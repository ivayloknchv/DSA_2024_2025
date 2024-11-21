// https://leetcode.com/problems/fibonacci-number/description/

class Solution {
public:

    int fib(int n, vector<int>& cache)
    {
        if(n==0)
        {
            return cache[0]=0;
        }
        
        if(n==1)
        {
            return cache[1]=1;
        }
        
        if(cache[n]!=-1)
        {
            return cache[n];
        }
        
        return cache[n] = fib(n-1, cache) + fib(n-2, cache);
    }
    int fib(int n) 
    {
        vector<int> fibCache(n+1, -1);

        return fib(n, fibCache); 
    }
};
