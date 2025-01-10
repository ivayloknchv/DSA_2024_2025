#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://github.com/azl397985856/leetcode/blob/master/problems/1168.optimize-water-distribution-in-a-village-en.md

struct UnionFind
{
	vector<int> parent;
	vector<int> size;

	UnionFind(int n)
	{
		parent.resize(n + 1);
		size.resize(n + 1, 1);

		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}

	int Find(int n)
	{
		return (parent[n] == n) ? n : parent[n] = Find(parent[n]);
	}

	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);

		if (px == py)
		{
			return;
		}

		if (size[px] > size[py])
		{
			parent[py] = px;
			size[px] += size[py];
		}

		else
		{
			parent[px] = py;
			size[py] += size[px];
		}
	}
	
};

class Solution
{
public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes)
	{
		for (int i = 1; i <= n; i++)
		{
			pipes.push_back({ 0, i, wells[i - 1] });
		}

		UnionFind uf(n + 1);

		sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });

		int components = n + 1;
		int result = 0;

		for (auto& pipe : pipes)
		{
			if (uf.Find(pipe[0]) != uf.Find(pipe[1]))
			{
				uf.Union(pipe[0], pipe[1]);
				result += pipe[2];
				components--;
			}

			if (components == 1)
			{
				break;
			}
		}
		return result;
	}
};
