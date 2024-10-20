#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool usedNums[(int)1e6+1];

int main()
{
    int N = 0, X = 0;
    cin >> N >> X;
    
    vector<int> monsters;

    for (int i = 0; i < N; i++)
    {
        int temp=0;
        cin>>temp;
        
        if(usedNums[temp])
        {
            continue;
        }
        
        monsters.push_back(temp);
        
        usedNums[temp]=true;
    }
    
    sort(monsters.begin(), monsters.end());
    
    int counter=0;
    int n=monsters.size()-1;
    
    for(int i = n; i >= 0; i--)
    {
        if(monsters[i]-counter*X<=0)
        {
            cout<<counter;
            break;
        }
        
        counter++;
    }
    return 0;
}
