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

const ll MOD = 1000000007;

ll binexp(ll a, ll k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        k >>= 1;
    }
    return ans;
}

// find inverse of a modulo MOD
inline ll modinv(ll a) { return fast(a, MOD - 2); }
