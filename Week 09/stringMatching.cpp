#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-9-2023/challenges/substring-frequency-1/problem

constexpr long long mod = 1e9+7;
constexpr int base = 31;

long long findHashVal(const string& s1, const vector<long long>& pow)
{
     long long hashVal = 0;
    
    for(int i = 0; i < s1.size(); i++)
    {
        hashVal = (hashVal + ((s1[i] - 'a') * pow[s1.size()-i-1]) % mod) % mod;
    }
    return hashVal;
    
}

vector<long long> findPows(long long maxPow)
{
    vector<long long> pow(maxPow+1);
    pow[0]=1;
    
    for(int i = 1; i < pow.size(); i++)
    {
        pow[i]= (base * pow[i-1]) % mod;
    }
    
    return pow;
}

int main() 
{ 
    string s1;
    string s2;
    
    cin>>s1>>s2;
    
    vector<long long> pow = findPows(s1.size());

    
    long long hashVal = findHashVal(s1, pow);
    long long counter = 0;

    
    long long curr=0;
    
    for(int i = 0; i < s1.size(); i++)
    {
        curr = (curr + ((s2[i]-'a')* pow[s1.size()-i-1]) % mod) % mod;
    }
    
    if(curr==hashVal)
    {
        counter++;
    }
    
    for(int i = s1.size(); i < s2.size(); i++)
    {
        curr = (curr - (s2[i - s1.size()] - 'a') * pow[s1.size() - 1] % mod + mod) % mod;
        curr = ((curr * base) % mod + (s2[i]-'a'));
        
        if(curr==hashVal)
        {
            counter++;
        }
    }
    
    cout<<counter;
    return 0;
}
