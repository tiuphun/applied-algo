#include <iostream>
using namespace std;
#define N 1000000
int n, k;               // nb of sq elements, nb of sub-sq elements
int a[N];
int w = 0;              // weight of k-sq
int maxWeight = 0;

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) w += a[i]; // initial sum
    if (w > maxWeight) maxWeight = w;

    for (int i = 1; i <= n-k; i++) {
        w = w + a[i+k-1] - a[i-1];          // sliding window
        if (w > maxWeight) maxWeight = w;
    }

    cout << maxWeight;
    return 0;
}
