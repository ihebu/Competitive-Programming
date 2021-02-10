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

const ll INF = 1e16;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    vll dist(n, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pll p = pq.top();
        pq.pop();
        int id = p.second;
        if (p.first != dist[id]) continue;
        for (pii e : adj[id])
        {
            int nxt = e.second;
            int w = e.first;
            ll ndist = dist[id] + w;
            if (ndist < dist[nxt])
            {
                dist[nxt] = ndist;
                pq.push({ndist, nxt});
            }
        }
    }

    for(int i = 1; i < n; i++) cout << dist[i] << " ";
    cout << "\n";
}
