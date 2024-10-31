#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list> 
using namespace std;

// https://www.hackerrank.com/contests/sda-2024-2025-hw03/challenges/npm-install-1

bool contains[100001]{};
list<int>::iterator positions[100001]{};
int N = 0, T = 0;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>T>>N;
    
    list<int> npm;
    
    while(T--)
    {
        int num=0;
        cin>>num;
        
        if(!contains[num])
        {
            if((int)npm.size()==N)
            {
            int first=npm.front();
            npm.pop_front();
            contains[first]=false;
            }
            
            npm.push_back(num);
            contains[num]=true;
            positions[num]=--npm.end();
            cout<<"false\n";
        }
        else
        {
            npm.erase(positions[num]);
            npm.push_back(num);
            positions[num]=--npm.end();
            cout<<"true\n";
        }
    }
    return 0;
}
