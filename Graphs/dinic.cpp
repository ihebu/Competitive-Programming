struct dinic
{
    struct edge
    {
        int a, b;
        ll c;
        edge(int a, int b, ll c) : a(a), b(b), c(c) {}
    };
    int s, t;
    vi level;
    vector<vi> adj;
    vector<edge> edges;
    queue<int> q;
    int m = 0;
    const ll INF = 1e18;

    dinic(int n, int s, int t) : s(s), t(t)
    {
        level.resize(n + 1);
        adj.resize(n + 1);
    }

    void add(int a, int b, ll c)
    {
        edges.emplace_back(a, b, c);
        edges.emplace_back(b, a, 0);
        adj[a].push_back(m++);
        adj[b].push_back(m++);
    }

    bool bfs()
    {
        fill(all(level), -1);
        level[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int a = q.front();
            q.pop();
            for (int id : adj[a])
            {
                int b = edges[id].b;
                ll c = edges[id].c;
                if (c == 0 || level[b] != -1) continue;
                level[b] = level[a] + 1;
                q.push(b);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int a, ll flow)
    {
        if (a == t || flow == 0) return flow;
        for (int id : adj[a])
        {
            int b = edges[id].b;
            ll c = edges[id].c;
            if ((level[b] <= level[a]) || c == 0) continue;
            ll f = dfs(b, min(flow, c));
            if (f == 0) continue;
            edges[id].c -= f;
            edges[id ^ 1].c += f;
            return f;
        }
        return 0;
    }

    ll maxflow()
    {
        ll ans = 0;
        while (bfs())
            while (ll flow = dfs(s, INF)) ans += flow;
        return ans;
    }
};