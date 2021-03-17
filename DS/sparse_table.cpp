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

const int N = 2e5;
const int K = log2(N);
int lg[N + 1];
int st[N][K + 1];
int n;

// change the query function depending on the problem
inline int f(int x, int y) { return min(x, y); }

// the table is 0-indexed
void build()
{
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; i++) cin >> st[i][0];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// query the range [l, r], l and r are inclusive
int query(int l, int r)
{
    int j = lg[r - l + 1];
    int ans = f(st[l][j], st[r - (1 << j) + 1][j]);
    return ans;
}
