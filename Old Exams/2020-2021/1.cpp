#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int N = 0, M = 0;
    cin>>N>>M;
    
    vector<int> arr1(N);
    vector<int> arr2(M);
    
    for(int i = 0; i < N; i++)
    {
        cin>>arr1[i];
    }
    
    for(int i = 0; i < M; i++)
    {
        cin>>arr2[i];
    }
    
    sort(arr1.begin(), arr1.end());
    
    for(int n : arr2)
    {
        auto lower = lower_bound(arr1.begin(), arr1.end(), n);
        
        cout<<lower-arr1.begin()<<' ';
    }
    
    
    return 0;
}
