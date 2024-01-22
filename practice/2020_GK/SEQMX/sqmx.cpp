#include <iostream>
#include <iomanip>
using namespace std;
#define N 100009
int n, k;
int a[N];
int sum = 0, maxSum = 0;
float maxAvg = 0.0f;
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < k) sum += a[i];
    }
    maxSum = sum;
    for (int i = 1; i <= n-k; i++) {
        sum = sum + a[i+k-1] - a[i-1]; // sliding window
        if (sum > maxSum) maxSum = sum;
    }
    maxAvg = (float)maxSum / k;
    cout << fixed << setprecision(5) << maxAvg << endl;
    return 0;
}
/*
7 3
2 4 5 1 3 4 1

3.66667*/