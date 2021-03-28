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

bool is_prime(ll p, int iter = 10)
{
    if (p < 4) return p == 2 || p == 3;

    for (int i = 0; i < iter; i++)
    {
        int a = 2 + rand() % (p - 3);
        if (modpow(a, p - 1, p) != 1) return false;
    }
    return true;
}
