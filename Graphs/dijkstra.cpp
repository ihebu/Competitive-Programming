struct dijkstra
{
    const ll INF = 1e18;
    vector<vector<pii>> adj;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vll dist;
    vi p;
    int s;

    dijkstra(int n, int s) : s(s)
    {
        adj.resize(n + 1);
        p.resize(n + 1);
        dist.resize(n + 1, INF);
    }

    void add(int a, int b, int c) { adj[a].push_back({b, c}); }

    void run()
    {
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty())
        {
            ll a, x;
            tie(x, a) = pq.top();
            pq.pop();
            if (x != dist[a]) continue;
            for (auto e : adj[a])
            {
                ll b, c;
                tie(b, c) = e;
                if (dist[a] + c < dist[b])
                {
                    dist[b] = dist[a] + c;
                    p[b] = a;
                    pq.push({dist[b], b});
                }
            }
        }
    }
};