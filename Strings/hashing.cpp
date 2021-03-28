// change these parameters depending on the problem constraints

const int MOD = 1e9 + 7;
const int B = 31;

const int N = 2e5;
ll p[N], pref[N];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    p[0] = 1;
    pref[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++)
    {
        p[i] = (p[i - 1] * B) % MOD;
        pref[i] = (pref[i - 1] * B + (s[i] - 'a' + 1)) % MOD;
    }

    // Rabin-Karp
    string k;
    cin >> k;
    int m = k.size();
    ll hash = 0;
    for (int i = 0; i < m; i++) hash = (hash * B + (k[i] - 'a' + 1)) % MOD;

    for (int i = 0; i < n - m + 1; i++)
    {
        ll x;
        if (i == 0) x = pref[m - 1];
        else
        {
            x = pref[i + m - 1] - (pref[i - 1] * p[m]) % MOD;
            x = (x + MOD) % MOD;
        }
        if (hash == x) cout << i << "\n";
    }
}