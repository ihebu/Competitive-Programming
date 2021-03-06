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

const int N = 1e7 + 5;
int lp[N];
vi primes;

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            primes.push_back(i);
        }
        int j = 0;
        while (j < primes.size() && primes[j] <= lp[i])
        {
            int x = i * primes[j];
            if (x > n) break;
            lp[x] = primes[j];
            j++;
        }
    }
    // can use the lp array for efficient prime factorisation
    // of numbers in the range [2..N]
}
