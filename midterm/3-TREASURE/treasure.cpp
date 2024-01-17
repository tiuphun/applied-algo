#include <iostream>
using namespace std;
#define MAX 1009
#define INF 1000000009
int n, m;               // nb row and col
int a[MAX][MAX];        // the cost matrix
int dp[MAX][MAX];

void stateTransition() {
    dp[0][0] = 1;
    for (int i = 0, j = 1; j < m; j++) {    // first row
        if (a[i][j] != 0 && a[i][j-1] != 0) dp[i][j] = a[i][j] + dp[i][j-1];    // prev node: only left
        else dp[i][j] = INF;
    }
    for (int i = 1, j = 0; i < m; i++) {    // first col
        if (a[i][j] != 0 && a[i-1][j] != 0) dp[i][j] = a[i][j] + dp[i-1][j];    // prev node: only above
        else dp[i][j] = INF;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != 0 && (a[i-1][j-1] != 0 || a[i-1][j] != 0 || a[i][j-1] != 0))
                dp[i][j] = a[i][j] + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            else dp[i][j] = INF;
        }
    }
}



int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
    }
    stateTransition();
    if (dp[n-1][m-1] >= INF) cout << -1; 
    else cout << dp[n-1][m-1];
    return 0;
}

/*
5 6
1 2 0 5 1 3
5 -9 2 0 1 3
1 4 1 5 7 4
-60 1 0 0 0 0
6 7 0 5 4 3

-1
*/

/*
5 6 
1 2 0 5 1 3 
5 -9 2 0 1 3
1 4 1 5 7 4
-60 1 9 0 29 0
6 7 0 5 4 3

-31
*/