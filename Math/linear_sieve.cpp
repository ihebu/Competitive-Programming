const int N = 1e7 + 5;
int p[N];
vi primes;

int main()
{
    for (int i = 2; i < N; i++)
    {
        if (p[i] == 0)
        {
            p[i] = i;
            primes.push_back(i);
        }
        int j = 0;
        while (j < primes.size())
        {
            int x = i * primes[j];
            if (primes[j] > p[i] || x >= N) break;
            p[x] = primes[j];
            j++;
        }
    }
}
