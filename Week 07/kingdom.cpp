#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/kontrolno-3/challenges/challenge-4346/problem

struct Node
{
    long long val = 0;
    vector<Node*> predecessors;

    Node(long long val) : val(val)
    {}
};


void DFS(Node* curr, vector<long long>& counter)
{
    if (!curr)
    {
        return;
    }

    for (long long i = 0; i < curr->predecessors.size(); i++)
    {
        counter[curr->val]++;
        DFS(curr->predecessors[i], counter);
        counter[curr->val] += counter[curr->predecessors[i]->val];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N = 0;
    cin >> N;

    vector<Node*> nodes(N);

    for (long long i = 0; i < N-1; i++)
    {
        long long x = 0, y = 0;

        cin >> x >> y;

        if (!nodes[x])
        {
            nodes[x] = new Node(x);
        }

        if (!nodes[y])
        {
            nodes[y] = new Node(y);
        }

        nodes[x]->predecessors.push_back(nodes[y]);
    }

    vector<long long> ans(N);

    DFS(nodes[0], ans);

    for (long long n : ans)
    {
        cout << n << ' ';
    }
    return 0;
}
