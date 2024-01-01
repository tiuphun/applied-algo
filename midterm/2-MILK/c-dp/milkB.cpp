#include <iostream>
#include <vector>
#include <numeric>
int n, year, ans;
using namespace std;
int main(int argc, char const *argv[])
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> year;

    int sum = accumulate(a.begin(), a.end(), 0);
    vector<vector<bool> > dp(n+1, vector<bool>(sum+1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < a[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
        }
    }

    ans = 0;
    for (int j = year; j <= sum; j++) {
        if (dp[n][j]) ans++;
    }

    cout << ans << endl;

    return 0;
}