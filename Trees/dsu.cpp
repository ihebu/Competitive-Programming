#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

// this file contains 2 different implementations for dsu

// dsu implementation using map (or unordered_map)
// use for general problems and different data types
template <typename T>
struct dsu
{
    map<T, T> root;
    map<T, int> size;

    T find(T u)
    {
        if (!root.count(u)) return root[u] = u;
        return root[u] == u ? u : root[u] = find(root[u]);
    }

    bool join(T u, T v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (!size.count(u)) size[u] = 1;
        if (!size.count(v)) size[v] = 1;
        if (size[u] < size[v]) swap(u, v);
        root[v] = u;
        size[u] += size[v];
        return true;
    }
};

// dsu implementation using a vactor
// use for better performance
struct dsu
{
    vector<int> root, size;

    dsu(int n)
    {
        size.resize(n + 1, 1);
        root.resize(n + 1);
        for (int i = 1; i < n; i++) root[i] = i;
    }

    int find(int u) { return root[u] == u ? u : root[u] = find(root[u]); }

    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (size[u] < size[v]) swap(u, v);
        root[v] = u;
        size[u] += size[v];
        return true;
    }
};
