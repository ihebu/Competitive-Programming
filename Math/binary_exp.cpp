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

ll modpow(ll a, ll k, ll mod)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ans;
}

inline ll modinv(ll a, ll mod) { return modpow(a, mod - 2, mod); }