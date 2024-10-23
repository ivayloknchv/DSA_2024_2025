#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-homework-3/challenges/challenge-2675/problem

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n = 0, q = 0;
    cin>>n>>q;
    
    vector<long long> grades(n);
    
    for(long long i = 0; i<n; i++)
    {
        cin>>grades[i];
    }
    
    sort(grades.begin(), grades.end());
    
    while(q--)
    {
        long long minGrade=0, maxGrade=0;
        cin>>minGrade>>maxGrade;
        
        if(minGrade>maxGrade)
        {
            cout<<0<<'\n';
            continue;
        }
        
        auto lower= lower_bound(grades.begin(), grades.end(), minGrade);
        auto upper= upper_bound(grades.begin(), grades.end(), maxGrade);
        
        cout<<upper-lower<<'\n';
    }
    return 0;
}
