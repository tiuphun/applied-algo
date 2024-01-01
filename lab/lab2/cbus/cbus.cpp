// Done
#include <iostream>
using namespace std;
#define MAX 30
int n;                          // number of passengers/ requests per se
int len;                        // 2*n, total elements in solution representation (bus stops)
int capacity;                   // number of available bus seats
int C[2*MAX+1][2*MAX+ 1];       // travelling distance matrix
bool appear[MAX];               // marking traveled points
int load;                       // number of current passengers on bus
int x[MAX];                     // current solution
int f;                          // current cost
int f_best;                     // best cost
int x_best[MAX];                // best solution
int cmin;                       // smallest element (diagonal excluded) of cost matrix
void input() {
    cin >> n >> capacity;
    len = 2*n;
    cmin = 1000000;
    for (int i = 0; i <= len; i++) 
        for (int j = 0; j <= len; j++) {
            cin >> C[i][j];
            if (i != j && cmin > C[i][j]) cmin = C[i][j];
        }
}

bool check(int v, int k) {
    if (appear[v] == 1) return 0;
    if (v > n) {
        if (!appear[v-n]) return 0;
    } else {
        if (load + 1 > capacity) return 0;
    }
    return 1;
}

void solution() {
    if (f + C[x[len]][0] < f_best) {
        f_best = f + C[x[len]][0];
        for (int i = 0; i <= len; i++) 
            x_best[i] = x[i];
    }
}

void TRY(int k) {
    for (int v = 1; v <= len; v++) {
        if (check(v, k)) {
            x[k] = v;
            f += C[x[k-1]][x[k]];
            if (v <= n) load += 1;
            else        load -= 1;
            appear[v] = 1;
            if (k == len) solution();
            else {
                if (f + (len+1-k) * cmin < f_best)
                    TRY(k+1);
            }
            if (v <= n) load -= 1;
            else        load += 1;
            appear[v] = 0;
            f -= C[x[k-1]][x[k]];
        }
    }
}

void solve() {
    load = 0;
    f = 0;
    f_best = 1000000;
    for (int i = 1; i <= len; i++) 
        appear[i] = 0;
    x[0] = 0;   // starting point
    TRY(1);
    printf("%d", f_best);
}

void print() {
    for (int i = 0; i <= len; i++) 
        printf("%d ", x_best[i]);
}

int main()
{
    input();
    solve();
    return 0;
}
