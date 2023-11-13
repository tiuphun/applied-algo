#include <iostream>
#include <cstring>
using namespace std;

int A[1001];                    // input array
int n;                          // number of elements
int res;                        // result   
int iMem[1001];                 // memory array
bool bMark[1001];               // mark array


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
    int tmp = 0, pos = -1;
    for (int i = 0; i < n; i++) {
        tmp = max(res, iMem[i]);
        if (tmp == iMem[i]) pos = i;        // after this loop pos is the position of the maximum sum
    }
    int first = pos, last = pos, sum = A[first];
    while (sum != res)
    {
        --first;
        sum += A[first];
    }
    cout << first << " " << last;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    memset(bMark, 0, sizeof(bMark));
    MaxSum(n);
    int tmp = 0;
    for (int i = 0; i < n; i++)
        res = max(tmp, iMem[i]);
    cout << res;
    Trace(n);
    TraceLoop();
    return 0;
}
