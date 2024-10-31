#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/sda-2024-2025-hw03/challenges/k--12/problem

struct Node
{
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) : data(data), next(next)
    {

    }
};

Node* reverseGroups(Node* head, int N, int k)
{
    if (head == nullptr) {
        return head;
    }

    Node* curr = head;
    Node* newHead = nullptr;
    Node* newTail = nullptr;
    int totalGroups = N / k;
    int groupCounter = 0;

    while (curr && groupCounter++ < totalGroups) 
    {
        Node* groupHead = curr;
        Node* groupPrev = nullptr;
        int elCounter = 0;

        while (curr && elCounter++ < k)
        {
            Node* next = curr->next;
            curr->next = groupPrev;
            groupPrev = curr;
            curr = next;
        }

        if (!newHead)
        {
            newHead = groupPrev;
        }

        if (newTail)
        {
            newTail->next = groupPrev;
        }

        newTail = groupHead;
    }

    while (newTail && curr)
    {
        newTail->next = curr;
        newTail = newTail->next;
        curr = curr->next;
    }

    return newHead;
}

int main()
{
    int N = 0, k = 0;
    cin >> N;

    Node* head = nullptr;
    Node* prev = nullptr;
    Node* curr = nullptr;

    for (int i = 0; i < N; i++)
    {
        int val = 0;
        cin >> val;
        curr = new Node(val);

        if (!head)
        {
            head = curr;
            prev = curr;
        }
        else
        {
            prev->next = curr;
            prev = curr;
        }
    }

    cin >> k;
    Node* rev = reverseGroups(head, N, k);

    while (rev)
    {
        cout << rev->data << ' ';
        rev = rev->next;
    }
    return 0;
}
