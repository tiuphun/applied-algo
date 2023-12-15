#include <iostream>
using namespace std;
#define N 100000
int n;          // size of array
int a[N];       // the sequence

int MaxLeftMid(int i, int j) {
    int maxLM = a[j];
    int s = 0;
    for (int k = j; k >= i; k--) {
        s += a[k];
        maxLM = max(maxLM, s);
    }
    return maxLM;
}

int MaxRightMid(int i, int j) {
    int maxRM = a[i];
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += a[k];
        maxRM = max(maxRM, s);
    }
    return maxRM;
}

int SubSeqMax(int i, int j) {
    if (i == j) return a[i];
    int mid = (i + j) / 2;
    int wL = SubSeqMax(i, mid);
    int wR = SubSeqMax(mid+1, j);
    int maxLM = MaxLeftMid(i, mid);
    int maxRM = MaxRightMid(mid+1, j);
    int wM = maxLM + maxRM;
    return max(max(wL, wR), wM);
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = SubSeqMax(0, n);
    cout << ans;
    return 0;
}

// IN: 7
// -16 7 -3 0 -1 5 -4
// OUT: 8