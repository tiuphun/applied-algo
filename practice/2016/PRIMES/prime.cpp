#include <iostream>
#include <vector>
using namespace std;

int n;                          // the integer
int k;                          // nb of primes constitude the sum
int totalCount = 0;             // total nb of ways
vector<bool> sieve(4001, true); // true if nb is prime
vector<int> primes;             // prime nbs

void generatePrimes() { // generates all prime numbers up to 4000 using the Sieve of Eratosthenes
    sieve[0] = false;
    sieve[1] = false;
    for (int p = 2; p*p <= 4000; p++) {
        if (sieve[p]) {
            for (int i = p*p; i <= 4000; i += p)
                sieve[i] = false;
        }
    }
    for (int p = 2; p <= 4000; p++) {
        if (sieve[p]) primes.push_back(p);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    generatePrimes();

    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 1;                   // dp[i][j] - nb of ways to represent i as sum of j primes
    for (int idx = 0; idx < primes.size(); idx++) {
        int p = primes[idx];
        for (int i = n; i >= p; i--) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] += dp[i-p][j-1];
            }
        }
    }
    
    for (int i = 1; i <= k; i++) totalCount += dp[n][i];
    cout << totalCount;
    return 0;
}
/*
28 4

5
*/