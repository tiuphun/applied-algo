// Done
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ii;      // pair of integers
const int maxN = 999 + 100;     // maximum number of rows and columns
const int oo = 1e9 + 7;         // infinity
int n;                          // number of rows
int m;                          // number of columns                  
int r;                          // starting row               
int c;                          // starting column
int a[maxN][maxN];              // the maze
int d[maxN][maxN];              // distance from (r, c) to (i, j)
int dx[] = {-1, 0, 1, 0},       // direction vectors
    dy[] = {0, 1, 0, -1};       // direction vectors
queue<ii> q;                    // queue for BFS
int solve() {
    q.push(ii(r, c));
    d[r][c] = 0;
    a[r][c] = 1;
    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > m || y < 1 || y > n) 
                return d[u.first][u.second] + 1;
            if (a[x][y] != 1) {
                d[x][y] = d[u.first][u.second] + 1;
                q.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // printf("Enter m, n, r, c (separated by a space): ");
    cin >> m >> n >> r >> c;
    // printf("Enter the maze matrix: \n");
    for (int i = 1; i <= m; i++)
        for (int j = 1; j<= n; j++)
            cin >> a[i][j];
    int ans = solve();
    // cout << "ans = " << ans << "\n";
    cout << ans;
    return 0;
}

// SAMPLE INPUT
// 8 12 5 6
// 1 1 0 0 0 0 1 0 0 0 0 1
// 1 0 0 0 1 1 0 1 0 0 1 1
// 0 0 1 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 1 0 0 1 0 1
// 1 0 0 1 0 0 0 0 0 1 0 0
// 1 0 1 0 1 0 0 0 1 0 1 0
// 0 0 0 0 1 0 1 0 0 0 0 0
// 1 0 1 1 0 1 1 1 0 1 0 1
// OUTPUT
// 7