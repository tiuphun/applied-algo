#include <iostream>
using namespace std;
#include <unordered_map>
#define N 100009
#define MOD 1000000007
int Q = 0;          // nb of equal pairs
int a[N];           // input sequence
int n;              // nb of elements in input

// Naive approach: O(n^2)
void naive() {
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] == a[j]) Q++;
        }
    }
    cout << Q % MOD;
}

// Using a hash map: O(n)
void optimized() {
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    Q = 0;
    for (auto &pair : count) {
        long long n = pair.second;
        Q += n * (n - 1) / 2;
    }
    cout << Q % MOD;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    optimized();
    return 0;
}

/*
6
1 2 2 1 3 1

4
*/