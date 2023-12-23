/* k-subseq bounded weight
a[1], a[2],..., a[n]
k-subseq ≈ k consecutive elements set
weight of a subseq = sum of all elements in this subseq
n, k, A, B
(1 <= n <= 10^5, 1 <= k <= n/2, 1 <= A, B <= 10^5)
Q, nb of k-subseq s.t. their weight w, A <= w <= B

5 3 6 18
2 2 8 8 3

2
*/
#include <iostream>
using namespace std;
#define N 100009
int n;      // nb of elements
int a[N];   // the sequence
int k;      // nb of elements in subseq
int A;      // lower bound of weight
int B;      // upper bound of weight
int sum[N];
void naive() {
    int count = 0;
    for (int i = 0; i <= n-k; i++) {
        sum[i] = 0;
        for (int j = 0; j < k; j++) {
            sum[i] += a[i+j];
            if (sum[i] > B) break;
        }
        if (sum[i] >= A && sum[i] <= B) count++;
    }
    cout << count;
}

int main(int argc, char const *argv[])
{
    cin >> n >> k >> A >> B;
    for (int i = 0; i < n; i++) cin >> a[i];
    naive();
    return 0;
}
