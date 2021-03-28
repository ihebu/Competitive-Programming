const int N = 1e7 + 5;
bitset<N> is_prime;
vector<int> primes;

int main()
{
    is_prime.set();
    for (int i = 2; i * i < N; i++)
    {
        if (!is_prime[i]) continue;
        for (int j = i * i; j < N; j += i) is_prime[j] = 0;
    }
    for (int i = 2; i < N; i++)
        if (is_prime[i]) primes.push_back(i);
}
