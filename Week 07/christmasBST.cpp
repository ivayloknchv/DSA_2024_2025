#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-5-2024/challenges/validate-bst-2/problem

struct Node
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right)
    {}
};

long long N = 0, T = 0;
constexpr long long MAX_SIZE = 3000001;


bool isValid(Node* curr, long long minVal, long long maxVal)
{
    if(!curr)
    {
        return true;
    }
    
    if(curr->val > minVal && curr->val < maxVal)
    {
        return isValid(curr->left, minVal, curr->val) &&
            isValid(curr->right, curr->val, maxVal);
    }
    
    return false;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while(T--)
    {
        cin>>N;
        vector<Node*> nodes(N);
        
        for (long long i = 0; i < N; i++)
        {
            long long val = 0, l = 0, r = 0;
            cin >> val >> l >> r;

            if (!nodes[i])
            {
                nodes[i] = new Node(val);
            }
            else
            {
                nodes[i]->val = val;
            }

            if (l != -1)
            {
                if (!nodes[l])
                {
                    nodes[l] = new Node(0);
                }
                nodes[i]->left = nodes[l];
            }
            if (r != -1)
            {
                if (!nodes[r])
                {
                    nodes[r] = new Node(0);
                }
                nodes[i]->right = nodes[r];
            }
        }
        
        bool ans = isValid(nodes[0], LLONG_MIN, LLONG_MAX);
        cout<<ans<<'\n';
    }
    return 0;
}
