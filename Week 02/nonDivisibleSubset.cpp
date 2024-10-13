// https://www.hackerrank.com/challenges/non-divisible-subset/problem

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> remainders(k);
    
    int counter=0;
    
    for(int i=0;i<s.size();i++)
    {
        remainders[s[i]%k]++;
    }
    
    if(remainders[0])
    {
        counter++;
    }
    
    for(int i = 1; i<=k/2;i++)
    {
        if(i==k-i)
        {
            counter++;
            continue;
        }
        
        counter+=max(remainders[i], remainders[k-i]);
    }
    
    return counter;
}
