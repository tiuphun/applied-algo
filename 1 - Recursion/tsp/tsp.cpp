// TSP: Branch and Bound
#include <iostream>
using namespace std;

int n;              // number of cities [1..n]
int c[100][100];    // cost matrix
int cmin = 1000000; // minimum element of the cost matrix, exclusive of the diagonal
int x[100];         // current solution
int visited[100];   // marking array: visited[i] = 1 if city i is visited, 0 otherwise
int f;              // current cost
int fopt;           // optimal cost

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; i++) {
            cin >> c[i][j];
        }
    }
}
void find_cmin () {
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; i++) {
            if (c[i][j] < cmin) cmin = c[i][j];
        }
    }
}
void TRY(int k) {
    for (int v = 1; v <= n; v++) {
        x[k] = v;
        visited[v] = 1;
        f += c[x[k-1]][k];
        if (k == n) {
            if (f + c[x[n]][1] < fopt) {
                fopt = f + c[x[n]][1];
            }
        }
        else {
            if (f + (n-k+1)*cmin < fopt) {
                TRY(k+1);
            }
        }
        f -= c[x[k-1]][k];
        visited[v] = 0;
    }
}
int main(int argc, char const *argv[])
{
    input();
    find_cmin();
    for (int i = 1; i <= n; i++) visited[i] = 0;
    f = 0;
    fopt = 0;
    x[1] = 1;
    visited[1] = 1;
    TRY(2);
    return 0;
}


