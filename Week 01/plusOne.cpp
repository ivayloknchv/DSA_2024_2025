#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        arr.push_back(num);
    }


    arr[arr.size() - 1] += 1;

    for (size_t i = arr.size()-1; i >= 1; i--)
    {
        int remainder = arr[i] % 10;

        if (remainder != 0)
        {
            break;
        }

        arr[i] = 0;
        arr[i - 1] += 1;
    }

    if (arr[0] == 10)
    {
        int size = arr.size();
        arr.resize(size + 1);
        for (int i = size-1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[0] = 1;
        arr[1] = 0;
    }

   for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
    return 0;
}
