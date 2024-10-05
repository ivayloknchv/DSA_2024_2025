#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string input;
    cin>>input;
    
    int size=input.size();
    
    int idx=0;
    
    while(idx<size)
    {
        char ch=input[idx];
        int counter=0;
        
        while(input[idx]==ch)
        {
            counter++;
            idx++;
        }
        
        cout<<counter<<ch;
    }
    return 0;
}
