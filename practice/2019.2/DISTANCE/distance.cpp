#include <iostream>
using namespace std;
#define N 1001
int n;              // nb points
int c[N][N];        // cost matrix
int p[N];           // list of points
int m;              // nb of points in route
int total = 0;      // total cost of given route
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> p[i];

    for (int i = 1; i <= m-1; i++) {
        int j = i+1;
        int cur = p[i], next = p[j];
        total += c[cur][next];
    }

    cout << total << endl;
    return 0;
}

/*
4
0 2 3 4
5 0 2 5
1 2 0 5
6 4 2 0
4
4 3 2 1

9
*/