#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


// https://www.hackerrank.com/contests/sda-hw-5-2024/challenges/vertical-sums/problem

struct Node
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right)
    {}
};

constexpr long long MAX_SIZE = 1000001;
Node* nodes[MAX_SIZE]{};
long long negativeArr[MAX_SIZE]{};
long long positiveArr[MAX_SIZE]{};
long long N, A;

void BFS(Node* curr)
{
    if (!curr)
    {
        return;
    }
    queue<pair<Node*, int>> q;
    q.push({ curr, 0 });

    while (!q.empty())
    {
        pair<Node*, long long> curr = q.front();
        q.pop();

        if (curr.second >= 0)
        {
            positiveArr[curr.second] += curr.first->val;
        }
        else
        {
            negativeArr[-curr.second-1] += curr.first->val;
        }

        if (curr.first->left)
        {
            q.push({ curr.first->left, curr.second - 1 });
        }
        if (curr.first->right)
        {
            q.push({ curr.first->right, curr.second + 1 });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

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

    BFS(nodes[0]);

    long long negSize = 0;
    while (negativeArr[negSize] != 0)
    {
        negSize++;
    }

    for (long long i =negSize-1; i >=0; i--)
    {
        if (negativeArr[i] != 0)
        {
            cout << negativeArr[i] << ' ';
        }
        else
        {
            break;
        }
    }
    for (long long i = 0; i < MAX_SIZE; i++)
    {
        if (positiveArr[i] != 0)
        {
            cout << positiveArr[i] << ' ';
        }
        else
        {
            break;
        }
    }

    return 0;
}
