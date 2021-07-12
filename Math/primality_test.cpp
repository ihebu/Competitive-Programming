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

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

bool is_prime(ll p, int iter = 10)
{
    if (p < 4) return p == 2 || p == 3;

    for (int i = 0; i < iter; i++)
    {
        ll a = uniform_int_distribution<int>(2, p - 2)(gen);
        if (modpow(a, p - 1, p) != 1) return false;
    }
    return true;
}
