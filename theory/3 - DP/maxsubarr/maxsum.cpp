#include <iostream>
using namespace std;

int A[1001];                    // input array
int iMem[1001];                 // memory array
bool bMark[1001];               // mark array
memset(bmark, 0, sizeof(bMark));

int MaxSum (int i) {
    if (i == 1)     return A[i];
    if (bMark[i])   return iMem[i];
    int res = max(A[i], A[i] + MaxSum(i-1));
    iMem[i] = res;
    bMark[i] = true;
    return res;
}

// Tracing by recursion
void Trace(int i) {
    if (i != 1 && iMem[i] == A[i] + iMem[i-1]) {
        Trace(i-1);
    }
    cout << A[i] << " ";
}

// Tracing by loop
void TraceLoop() {
    int ans = 0, pos = -1;
    for (int i = 0; i < n; i++) {
        ans = max(res, iMem[i]);
        if (ans == iMem[i]) pos = i;
    }
    cout << ans << endl;
    int first = pos, las = pos, sum = A[first];
    while (sum != res)
    {
        --first;
        sum += A[first];
    }
    cout << first << " " << last;
}

int main(int argc, char const *argv[])
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, iMem[i]);
    }
    cout << ans;
    return 0;
}
