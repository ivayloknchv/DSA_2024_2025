#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct numInfo
{
    int num = 0;
    int pos = 0;
};

bool operator<(const numInfo& lhs, const numInfo& rhs)
{
    return (lhs.num < rhs.num) || ((lhs.num == rhs.num) && (lhs.pos<rhs.pos));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int n, k;
    cin >> n >> k;
    vector<numInfo> arr;

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        arr.push_back({ num,i });
    }

    sort(arr.begin(), arr.end());

    vector<int> result;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int sum = arr[left].num + arr[right].num;

        if ( sum == k)
        {
            result.push_back(arr[left].pos);
            result.push_back(arr[right].pos);
            break;
        }
        else if (sum < k)
        {
            left++;
        }
        else if (sum > k)
        {
            right--;
        }
    }

    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
    return 0;
}
