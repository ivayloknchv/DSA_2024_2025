#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://action.informatika.bg/problems/117

bool check(long long N, long long F, long long test)
{
	long long sum = (2 * F + (test - 1)) * test / 2;

	return sum >= N;
}

int main()
{
	long long N = 0, F = 0;
	cin >> N >> F;

	long long l = 0;
	long long r = LONG_MAX;
	
	long long ans = LONG_MAX;

	while (l <= r)
	{
		long long mid = l + (r - l) / 2;

		if (check(N, F, mid))
		{
			ans = min(ans, mid);
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	cout << ans;

	return 0;
}
