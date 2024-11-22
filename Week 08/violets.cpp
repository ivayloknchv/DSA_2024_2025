#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-6-2024/challenges/violets/problem

int main() {
    vector<int> flowers;
    flowers.push_back(0);
    flowers.push_back(2);
    flowers.push_back(2);
    
    int n = 0;
    cin>>n;
    
     for (int i = 3; i <= n; i++) 
     {
        int res = (flowers[i - 1] + flowers[i - 2]) %  1000000007;
        flowers.push_back(res);
    }
    cout<<flowers[n];
    return 0;
}
