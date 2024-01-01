// Done
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1000001;    // maximum number of elements
int n;                      // number of elements
int M[30][MAXN];            // M[j][i] = index of the minimum element in the range [i, i + 2^j - 1]
int A[MAXN];                // the array

// Building the segment tree
void preprocessing() {
    for (int j = 0; (1 << j) <= n; j++) {
        for (int i = 0; i < n; i++)
            M[j][i] = -1;
    }
    for (int i = 0; i < n; i++)
        M[0][i] = i;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]])
                M[j][i] = M[j - 1][i];
            else
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
        }
    }
}

// Querying the segment tree
int rmq(int i, int j) {
    int k = log2(j - i + 1);
    int p2k = (1 << k); // 2^k
    if (A[M[k][i]] <= A[M[k][j - p2k + 1]]) {
        return M[k][i];
    } else {
        return M[k][j - p2k + 1];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    preprocessing();
    int ans = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int I, J;
        scanf("%d %d", &I, &J);
        ans += A[rmq(I, J)];
    }
    cout << ans;
    return 0;
}

