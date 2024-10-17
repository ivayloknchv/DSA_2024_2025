#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/si-practice-2/challenges/task-3-1-2/problem

int N, K;


void merge(vector<int>& vec, int l, int mid, int r, vector<int>& buff)
{
    int left_start = l;
    int left_end = mid;
    int right_start = mid + 1;

    int idx = l;

    while (left_start <= left_end && right_start <= r)
    {
        if (vec[left_start] <= vec[right_start])
        {
            buff[idx++] = vec[left_start++];
        }
        else
        {
            buff[idx++] = vec[right_start++];
        }
    }

    while (left_start <= left_end)
    {
        buff[idx++] = vec[left_start++];
    }

    while (right_start <= r)
    {
        buff[idx++] = vec[right_start++];
    }

    for (int i = l; i <= r; i++)
    {
        vec[i] = buff[i];
    }
}

void merge_sort(vector<int>& vec, int l, int r, vector<int>& buff)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        merge_sort(vec, l, mid, buff);
        merge_sort(vec, mid + 1, r, buff);
        merge(vec, l, mid, r, buff);
    }
}

void merge_sort(vector<int>& vec)
{
    vector<int> buff(vec.size());
    merge_sort(vec, 0, vec.size() - 1, buff);

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N >> K;

    vector<int> vec(N);

    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        cin >> temp;
        vec[i] = temp;
    }

    merge_sort(vec);

    int sum = 0;
    int idx = 0;

    while (idx < N && sum  + vec[idx] <= K)
    {
        sum += vec[idx++];
    }

    cout << idx;

    return 0;
}
