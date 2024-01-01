// This approach is proudly suggested by my friend @haidodev. Go check him out!
#include <iostream>
using namespace std;
#define N 1000
int n;              // nb of days in schedule
int k1;             // least nb of working days
int k2;             // max nb of working days
int dp[N][N];       // nb of ways to sched: [i][j] at day i, already work for j days
int result = 0; 

int dpNurse() {
    if (k1 > k2 || n < k1) return 0;
    if (n == 1 || n == k1) return 1;
    if (n == k2) return 2;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
        for (int k = k1; k <= k2; k++) {
            dp[i][0] += dp[i-1][k];
        }
        for (int j = k1; j <= k2; j++) {
            dp[i][j] = dp[i-1][j-1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += dp[i][j];
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    cin >> n >> k1 >> k2;
    int ans = dpNurse();
    cout << ans;
    return 0;
}

// lam theo cach cua dohai ma dang bi sai