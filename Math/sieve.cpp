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

const int N = 1e7;
bitset<N> p;
vector<int> primes;

int main()
{
    p.set();
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (p[i])
            for (int j = i * i; j <= n; j += i) p[j] = 0;
    for (int i = 2; i <= n; i++)
        if (p[i]) primes.push_back(i);
}
