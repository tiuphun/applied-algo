// DP with Bitmasks
#include <iostream>
using namespace std;
const int N = 20;
const int INF = 100000000;
int C[N][N];
int iMem[N][1<<N]; // 1<<N = 2^0 + 2^1 +...+ 2^N = 2^(N+1) - 1

int TSP(int i, int S) {
    if (S == ((1 << N) - 1))    return C[i][0];
    if (iMem[i][S] != -1)       return iMem[i][S];
    int res = INF;
    for (int j = 0; j < N; j++) {
        if (S & (1 << j))
            continue;
        res = min(res, C[i][j] + TSP(j, S | (1 << j)));
    }
    iMem[i][S] = res;
    return res;
}

void Trace(int i, int S) {
    cout << i << " ";
    if (S == ((1 << N) - 1)) return;
    int res = iMem[i][S];
    for (int j = 0; j < N; j++) {
        if (S & (1 << j))
            continue;
        if (res == C[i][j] + iMem[j][S | (1 << j)]) {
            Trace(j, S | (1 << j));
            break;
        }
    }
}