#include <iostream>
using namespace std;
#define N 100009
int T;
int n;
int a[N];
unordered_map<int, int> dp;
int ans;

int main(int argc, char const *argv[])
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        dp.clear();
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[a[i]] = dp[a[i] - 1] + 1;    // if a[i]-1 not present, then simply no entry in hash map (= 1)
            ans = max(ans, dp[a[i]]);
        }
        cout << ans;
    }

    return 0;
}
/*
1 
6
3 1 2 4 3 5

3
*/