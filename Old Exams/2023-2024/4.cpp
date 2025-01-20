#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

using ll = long long;

struct UnionFind
{
    vector<ll> parent;
    vector<ll> size;
    vector<ll> weights;

    UnionFind(ll n)
    {
        parent.resize(n);
        size.resize(n, 1);
        weights.resize(n, 0);

        for (ll i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    ll Find(ll n)
    {
        if (parent[n] == n)
        {
            return n;
        }

        return parent[n] = Find(parent[n]);
    }

    void Union(ll x, ll y, ll w = 0)
    {
        ll px = Find(x);
        ll py = Find(y);

        if (px == py)
        {
            return;
        }

        if (size[px] > size[py])
        {
            parent[py] = px;
            size[px] += size[py];
            weights[px] += weights[py] + w;
        }

        else
        {
            parent[px] = py;
            size[py] += size[px];
            weights[py] += weights[px] + w;
        }
    }

    ll Calculate(ll K)
    {
        for (ll i = 0; i < parent.size(); i++)
        {
            Find(i);
        }
        
        ll res = 0;
        unordered_set<ll> p(parent.begin(), parent.end());


        for (ll n : p)
        {
            if (size[n] % K == 0)
            {
                res += weights[n];
            }
        }

        return res;
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll T = 0;
    cin >> T;


    while (T--)
    {
        ll V = 0, E = 0, K = 0;
        cin >> V >> E >> K;

        UnionFind uf(V);

        vector<pair<ll, pair<ll, ll>>> edges;

        for (ll i = 0; i < E; i++)
        {
            ll x = 0, y = 0, w = 0;
            cin >> x >> y >> w;

            edges.push_back({ w, {x, y} });
        }

        sort(edges.begin(), edges.end());

        for (auto& edge : edges)
        {
            ll x = edge.second.first;
            ll y = edge.second.second;
            ll w = edge.first;

            if (uf.Find(x) != uf.Find(y))
            {
                uf.Union(x, y, w);
            }
        }

        cout << uf.Calculate(K) << '\n';
    }
    return 0;
}
