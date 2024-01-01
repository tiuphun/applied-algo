#include <iostream>
using namespace std;
#define MAX 50
int n;                  // number of positive integers
int M;                  // sum (RHS) of the equation
int a[MAX];             // coefficients
int t[MAX];             // temporary array
int X[MAX];             // solution
int f;                  // accumulated sum of the solution
int ans;              // number of positive solutions

void input() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
}
void solution() {
    if (f == M)
        ans++;
}

void TRY(int k) {
    int v;
    for (v = 1; v <= (M - f - (t[n] - t[k])) / a[k]; v++) {
        X[k] = v;
        f += a[k] * X[k];
        if (k == n) solution();
        else TRY(k+1);
        f -= a[k] * X[k];
    }
}

void solve() {
    f = 0;
    t[1] = a[1];
    for (int i = 2; i <= n; i++)
        t[i] = t[i-1] + a[i];
    ans = 0;
    TRY(1);
    cout << ans;
}

int main(int argc, char const *argv[])
{
    input();
    solve();
    return 0;
}
