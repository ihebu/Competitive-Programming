// clang-format off

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fastio ios_base::sync_with_stdio(false), cin.tie(0)
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define case(i) cout << "Case #" << i << ": "

// clang-format on

const int N = 1e6 + 5;
const int LOG = 25;
int par[N][LOG];
int depth[N];

int kth(int a, int k)
{
    for (int j = 0; j < LOG; j++)
        if (k & (1 << j)) a = par[a][j];
    return a;
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    a = kth(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int j = LOG - 1; j >= 0; j--)
        if (par[a][j] != par[b][j])
        {
            a = par[a][j];
            b = par[b][j];
        }
    return par[a][0];
}

void test_case()
{
    int n;
    cin >> n;

    // setup and clear previous data structures here
    // read tree here
    // evaluate depth and parents here

    for (int k = 1; k < LOG; k++)
        for (int i = 1; i <= n; i++) par[i][k] = par[par[i][k - 1]][k - 1];
}

int main()
{
    fastio;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //
        test_case();
    }
}
