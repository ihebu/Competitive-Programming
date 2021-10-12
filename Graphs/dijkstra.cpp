// clang-format off

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define case(i) cout << "Case #" << i << ": "

// clang-format on

const ll INF = 1e18;
const int N = 1e5 + 5;
ll dist[N];
int par[N];
bool vis[N];
vector<pii> adj[N];
int n, m;

void clean()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        vis[i] = false;
        adj[i].clear();
    }
}

void dijkstra()
{
    set<pll> pq;
    pq.insert({0, 1});
    while (!pq.empty())
    {
        auto p = *pq.begin();
        pq.erase(pq.begin());
        int a = p.second;
        if (vis[a]) continue;
        vis[a] = true;
        for (auto e : adj[a])
        {
            ll c = e.first;
            int b = e.second;
            if (dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
                par[b] = a;
                pq.insert({dist[b], b});
            }
        }
    }
}

void test_case()
{
    cin >> n >> m;
    clean();
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dist[1] = 0;
    dijkstra();
}

int main()
{
    fastio;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //
        test_case();
    }
}
