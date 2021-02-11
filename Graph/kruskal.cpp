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

struct DSU
{
    vector<int> root, size;

    DSU(int n)
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

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<pair<int, pii>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        int c = edges[i].first;
        int a = edges[i].second.first, b = edges[i].second.second;
        if (dsu.join(a, b)) ans += c;
    }
    cout << ans << "\n";
}