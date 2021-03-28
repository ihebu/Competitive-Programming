const ll INF = 1e16;

typedef tuple<int, int, int> edge;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> egdes(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }

    vll dist(n + 1, INF), p(n + 1, -1);
    dist[1] = 0;

    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (int j = 0; j < m; j++)
        {
            int a, b, c;
            tie(a, b, c) = e[j];
            if (dist[a] == INF) continue;
            if (dist[a] + c < dist[b])
            {
                dist[b] = max(-INF, dist[a] + c);
                p[b] = a;
                x = b;
            }
        }
        if (x == -1) break;
    }
}
