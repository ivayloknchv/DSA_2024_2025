#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/exam-2020-02-06-sda/challenges/challenge-2851/problem

int main() {
    int N = 0, M = 0;
    
    cin>>N>>M;
    
    vector<int> arr1(N);
    vector<int> arr2(M);
    
    for(int i = 0; i < N; i++)
    {
        cin>>arr1[i];
    }
    
    for(int i = 0; i<M; i++)
    {
        cin>>arr2[i];
    }
    
    sort(arr1.begin(), arr1.end());
    
    for(int i = 0; i<M; i++)
    {
        auto it = lower_bound(arr1.begin(), arr1.end(), arr2[i]);
        
        cout << it - arr1.begin() << ' ';
    }
    
    return 0;
}
