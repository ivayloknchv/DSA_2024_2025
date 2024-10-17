#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 

int N, Q;

long long mergeAndCount(vector<int>& vec, int l, int mid, int r, vector<int>& buff)
{
    long long res = 0;

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
            res += (left_end - left_start) + 1;
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

    return res;
}

long long countInversions(vector<int>& vec, int l, int r, vector<int>& buff)
{
    long long res = 0;

    if (l < r)
    {
        int mid = l + (r - l) / 2;
        res += countInversions(vec,l,mid,buff);
        res += countInversions(vec, mid + 1, r, buff);
        res += mergeAndCount(vec, l, mid, r, buff);
    }

    return res;
}

long long countInversions(vector<int>& vec)
{
    vector<int> buff(vec.size());

    return countInversions(vec, 0, vec.size() - 1, buff);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> N;

    while (N--)
    {
        cin >> Q;
        vector<int> vec(Q);

        for (int i = 0; i < Q; i++)
        {
            int temp = 0;
            cin >> temp;
            vec[i] = temp;
        }
        cout << countInversions(vec)<<'\n';
    }

    return 0;
}
