// An improvement using Sliding Window technique
#include <iostream>
using namespace std;
#define N 100009
int n;      // nb of elements
int a[N];   // the sequence
int k;      // nb of elements in subseq
int A;      // lower bound of weight
int B;      // upper bound of weight
int sum[N];

bool inRange(int sum) {
    return (sum >= A && sum <= B);
}
void SlidingWindow() {
    int count = 0;
    for (int i = 0; i < k; i++) sum[0] += a[i];
    if (inRange(sum[0])) count++;
    for (int i = 1; i <= n-k; i++) {
        sum[i] = sum[i-1] - a[i-1] + a[i+k-1];
        if (inRange(sum[i])) count++;
    }
    cout << count;
}

int main(int argc, char const *argv[])
{
    cin >> n >> k >> A >> B;
    for (int i = 0; i < n; i++) cin >> a[i];
    SlidingWindow();
    return 0;
}