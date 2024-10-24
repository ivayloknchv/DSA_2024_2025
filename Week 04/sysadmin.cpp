#include <iostream>
#include <vector>
#include <algorithm>

// https://action.informatika.bg/problems/130

using namespace std;

bool check(const vector<long long>& cables, long long test, long long goal)
{
	long long total = 0;

	for (int cable : cables)
	{
		total += cable / test;
	}

	return total >= goal;
}

int main()
{
	long long N = 0, K = 0;

	cin >> N >> K;

	vector<long long> cables(N);

	long long maxVal = LLONG_MIN;

	for (long long i = 0; i < N; i++)
	{
		cin >> cables[i];
		maxVal = max(maxVal, cables[i]);
	}

	long long l = 1;
	long long r = maxVal;

	long long ans = 0;

	while (l <= r)
	{
		long long mid = l + (r - l) / 2;

		if (check(cables, mid, K))
		{
			ans = max(ans, mid);
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}

	cout << ans;

	return 0;
}
