const ll INF = 1e16;

int main()
{
    int n, m, q;
    cin >> n >> m;
    vector<vll> dist(n, vll(n, INF));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = min((ll)c, dist[a][b]);
    }

    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // negative cycle detection
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (dist[i][k] != INF && dist[k][k] < 0 && dist[k][j] != INF)
                    dist[i][j] = -INF;
}
