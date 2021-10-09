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

const int N = 2e5 + 5;
int bit[N];

int sum(int r)
{
    int ans = 0;
    for (; r; r -= r & -r) ans += bit[r];
    return ans;
}

int sum(int l, int r) { return sum(r) - sum(l - 1); }

void add(int l, int val)
{
    for (; l < N; l += l & -l) bit[l] += val;
}

void add(int l, int r, int val)
{
    add(l, val);
    add(r + 1, -val);
}

void test_case()
{
    //
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
