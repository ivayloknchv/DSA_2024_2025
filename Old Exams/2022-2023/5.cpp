#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0;
    cin>>N;
    
    unordered_map<int, int> counter;
    unordered_map<int, int> bestAt;
    
    vector<int> times;
    
    int maxCount = 0;
    int maxID = 0;
    
    for(int i  = 0; i < N; i++)
    {
        int id = 0, time = 0;
        cin>>id>>time;
        
        counter[id]++;
        times.push_back(time);
        
        if(counter[id] >= maxCount)
        {
            maxCount = counter[id];
            maxID = id;
        }
        
        bestAt[time] = maxID;
    }
    
    int T = 0;
    cin>>T;
    
    while(T--)
    {
        int q = 0;
        cin>>q;
        
        if(q<times[0])
        {
            cout<<-1<<'\n';
            continue;
        }
        
        auto upper = upper_bound(times.begin(), times.end(), q);
        upper--;
        
        cout<<bestAt[*upper]<<'\n';
    }
    
    return 0;
}
