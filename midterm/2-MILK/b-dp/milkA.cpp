#include <iostream>
#include <vector>
using namespace std;

#define N 25
int n, year, a[N];
vector<vector<int> > dp(N, vector<int>(2005, -1));

int countWays(int i, int sum) { // nb of ways to achieve the sum using the first i elements of the array
    if (i == 0 && sum > 0) return 0;
    if (sum <= 0) return 1;
    if (dp[i][sum] != -1) return dp[i][sum];
    // for each element, either it is included (i-1, sum-a[i-1]) or not (i-1, sum)
    dp[i][sum] = countWays(i-1, sum) + countWays(i-1, sum-a[i-1]);
    return dp[i][sum];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> year;
    cout << countWays(n, year) << endl;
    return 0;
}