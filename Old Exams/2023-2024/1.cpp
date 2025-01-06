#include <iostream>
#include <unordered_map>
using namespace std;

bool canRemove(int counter[])
{
    for(int i = 0; i < 26; i++)
    {
        if(!counter[i])
        {
            continue;
        }
        
        counter[i]--;
        
        
        int sum = 0;
        int activeLetters = 0;
        
        for(int i = 0; i < 26; i++)
        {
            sum+=counter[i];
            
            if(counter[i])
            {
                activeLetters++;
            }
        }
        
        int avg = sum / activeLetters;
        
        bool flag = true;
        
        for(int i = 0; i < 26; i++)
        {
            if(counter[i] && counter[i]!=avg)
            {
                flag = false;
                break;
            }
        }
        
        counter[i]++;
        
        if(flag)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int n = 0;
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        
        int counter[26]{};
        
        for(char ch : str)
        {
            counter[ch-'a']++;
        }
        
        cout<<canRemove(counter)<<'\n';
        
    }
    return 0;
}
