typedef vector<vll> matrix;
const ll MOD = 1000000007;

// identity matrix of size n x n
matrix id(int n)
{
    matrix a(n, vll(n, 0));
    for (int i = 0; i < n; i++) a[i][i] = 1;
    return a;
}

matrix operator*(matrix a, matrix b)
{
    int n = a.size(), p = a[0].size(), m = b[0].size();
    matrix c(n, vll(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++) c[i][j] += (a[i][k] * b[k][j]) % MOD;
            c[i][j] %= MOD;
        }
    return c;
}

// binary exponentiation of a square matrix
matrix modpow(matrix a, ll k)
{
    int n = a.size();
    matrix ans = id(n);
    while (k)
    {
        if (k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}
