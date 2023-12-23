// Done
/* Denote X = X1, X2, …, Xn, a subsequence of X is created by removing some element from X.  
Given two sequences X = X1, X2, …, Xn and Y = Y1, Y2, …, Ym.
Find a common subsequence of X and Y such that the length is the longest.
Input
Line 1: two positive integers n and m (1 <= n,m <= 10000)
Line 2: n integers X1, X2, …, Xn
Line 3:  m integers Y1, Y2, …, Ym
Output
Length of the longest subsequence of X and Y
Example 
Input
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
Output
5 */
#include <iostream>
using namespace std;
#define SIZE 10001
int n, m;                   // nb of elements of X, Y
int X[SIZE], Y[SIZE];       // the sequences
int dp[SIZE][SIZE];         // dp[i][j] is length of LCS of X[1..i], Y[1..j]

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        dp[i][0] = 0;
    }
    for (int j = 1; j <= m; j++) {
        cin >> Y[j];
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i] == Y[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}

