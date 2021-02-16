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

struct edge
{
    int first, second, weight;
};

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<edge> e(m);
    for (int i = 0; i < m; i++) cin >> e[i].first >> e[i].second >> e[i].weight;

    vi parent(n + 1, -1);
    vll dist(n + 1, INF);
    dist[1] = 0;

    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int j = 0; j < m; j++)
        {
            int a = e[j].first;
            int b = e[j].second;
            int c = e[j].weight;
            if (dist[a] == INF) continue;
            if (dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }
    if (x == -1) cout << "NO\n";
    else
    {
        int y = x;
        for (int i = 0; i < n; i++) y = parent[y];
        vector<int> path;
        for (int cur = y;; cur = parent[cur])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1) break;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n";
        for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
        cout << "\n";
    }
}
