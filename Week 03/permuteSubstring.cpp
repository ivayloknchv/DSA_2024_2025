#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/practice-1-si/challenges/task-3-1-1/problem

int main() {
    string str1, str2;
    cin>>str1>>str2;
    
    int firstCount[26]{0};
    int secondCount[26]{0};
    
    for(size_t i=0;i<str1.size();i++)
    {
        firstCount[str1[i]-'a']++;
    }
    for(size_t i=0;i<str2.size();i++)
    {
        secondCount[str2[i]-'a']++;
    }
    
    string res="";
    
    for(int i=0;i<26;i++)
    {
        int reps=min(firstCount[i],secondCount[i]);
    
        res+=std::string(reps,'a'+i);
    }
    
    cout<<res;
    
    return 0;
}
