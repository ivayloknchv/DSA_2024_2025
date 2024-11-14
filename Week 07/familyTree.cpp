#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.hackerrank.com/contests/sda-hw-5-2024/challenges/parent/problem

struct Node
{
    long long val = 0;
    vector<Node*> predecessors;

    Node(long long val) : val(val)
    {}
};

constexpr long long MAX_SIZE = 1000001;
Node* nodes[MAX_SIZE]{};
long long N = 0, Q = 0;
long long inTime[MAX_SIZE]{};
long long outTime[MAX_SIZE]{};
long long counter = 0;


void DFS(Node* curr)
{
    if (!curr)
    {
        return;
    }

    inTime[curr->val] = counter++;

    for (size_t i = 0; i < curr->predecessors.size(); i++)
    {
        DFS(curr->predecessors[i]);
    }

    outTime[curr->val] = counter++;

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (long long i = 0; i < N-1; i++)
    {
        long long a = 0, b = 0;
        cin >> a >> b;

        if (!nodes[a])
        {
            nodes[a] = new Node(a);
        }
        if (!nodes[b])
        {
            nodes[b] = new Node(b);
        }

        nodes[a]->predecessors.push_back(nodes[b]);
    }


    DFS(nodes[0]);
    cin >> Q;

    for (long long i = 0; i < Q; i++)
    {
        long long x = 0, y = 0;
        cin >> x >> y;

        if (inTime[x] < inTime[y] && outTime[y] < outTime[x])
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
