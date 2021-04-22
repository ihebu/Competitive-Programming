struct trie
{
    const static int k = 26;
    struct node
    {
        int edges[k];
        node() { fill(edges, edges + k, -1); }
        int& operator[](int i) { return edges[i]; }
    };

    vector<node> nodes;

    trie() { nodes.emplace_back(); }

    void add(const string& word)
    {
        int i = 0;
        for (char c : word)
        {
            int j = c - 'a';
            if (nodes[i][j] == -1)
            {
                nodes[i][j] = nodes.size();
                nodes.emplace_back();
            }
            i = nodes[i][j];
        }
    }
};