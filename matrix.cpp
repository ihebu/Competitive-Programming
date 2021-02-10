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

#define matrix vector<vll>
const ll MOD = 1000000007;

// return the identity matrix of size n x n
matrix id(int n)
{
    matrix a(n, vll(n, 0));
    for (int i = 0; i < n; i++)
        a[i][i] = 1;
    return a;
}

// matrix multiplication
matrix mul(matrix a, matrix b)
{
    int n = a.size(), p = a[0].size(), m = b[0].size();
    matrix c(n, vll(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
            c[i][j] %= MOD;
        }
    return c;
}

// fast exponentiation
matrix fast(matrix a, ll k)
{
    int n = a.size();
    matrix ans = id(n);
    while (k)
    {
        if (k & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        k >>= 1;
    }
    return ans;
}
