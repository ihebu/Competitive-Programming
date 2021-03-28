// dsu implementation using a map (or unordered_map)
template <typename T>
struct dsu
{
    map<T, T> root;
    map<T, int> size;

    T find(T u)
    {
        if (!root.count(u)) return root[u] = u;
        return root[u] == u ? u : root[u] = find(root[u]);
    }

    bool join(T u, T v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (!size.count(u)) size[u] = 1;
        if (!size.count(v)) size[v] = 1;
        if (size[u] < size[v]) swap(u, v);
        root[v] = u;
        size[u] += size[v];
        return true;
    }
};

// dsu implementation using a vactor
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
