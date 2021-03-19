const int N = 1e7 + 5;

// calculate phi for a range of numbers
int main()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i < N; i++) phi[i] = i;

    for (int i = 2; i < N; i++)
    {
        if (phi[i] != i) continue;
        for (int j = i; j <= N; j += i) phi[j] -= phi[j] / i;
    }
}

// calculate phi for a single number
int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0) n /= i;
            ans -= ans / i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}