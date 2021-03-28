typedef tuple<int, int, int> edge;

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

int main()
{
    int n, m;
    cin >> n >> m;
    dsu ds(n);
    vector<edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        tie(c, a, b) = edges[i];
        if (ds.join(a, b)) ans += c;
    }
}