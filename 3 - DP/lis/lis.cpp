#include <iostream>
#include <cstring>
using namespace std;
int A[1001];        // the sequence A
int iMem[1001];     // iMem[i]: the result of subproblem i
int n;              // size of A
int res = 1;        // the result of subproblem

int LIS(int i) {
    if (iMem[i] != -1) return iMem[i];
    for (int j = 1; j < i; j++) {
        if (A[j] < A[i]) {  // A[j] will only count as a candidate for LIS(i) when satisfy
            res = max(res, 1 + LIS(j));
        }
    }
    iMem[i] = res;
    return res;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
}
int main(int argc, char const *argv[])
{
    input();
    memset(iMem, -1, sizeof(iMem));
    int ans = 0;    // final global answer
    int pos = 0;    // mark the end position of LIS
    LIS(1);
    for (int i = 0; i < n; i++) {
        ans = max(ans, iMem[i]);
        if (ans == iMem[i]) pos = i;
    }
    cout << ans;
    return 0;
}

