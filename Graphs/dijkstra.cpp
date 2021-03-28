const ll INF = 1e16;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    vll dist(n + 1, INF), p(n + 1, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll a, x;
        tie(x, a) = pq.top();
        pq.pop();
        if (x != dist[a]) continue;
        for (auto e : adj[a])
        {
            ll b, c;
            tie(c, b) = e;
            if (dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
                p[b] = a;
                pq.push({dist[b], b});
            }
        }
    }
}
