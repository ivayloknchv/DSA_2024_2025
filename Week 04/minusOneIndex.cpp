#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://github.com/desiish/SDA_2024_2025/tree/main/Sem04

int solution(const vector<int>& X, const vector<int>& Y)
{
	int l = 0;
	int r = Y.size() - 1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (Y[mid] == -1)
		{
			return mid;
		}

		else if (X[mid] == Y[mid])
		{
			l = mid + 1;
		}

		else
		{
			r = mid - 1;
		}
	}

return -1;
}
