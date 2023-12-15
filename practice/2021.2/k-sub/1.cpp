/* k-subseq bounded weight
a[1], a[2],..., a[n]
k-subseq ≈ k consecutive elements set
weight of a subseq = sum of all elements in this subseq
k, A, B
Q, nb of k-subseq s.t. their weight w, A <= w <= B
*/
#include <iostream>
using namespace std;
#define N 100000
int n;      // nb of elements
int a[N];   // the sequence
int k;      // nb of elements in subseq
int A;      // lower bound of weight
int B;      // upper bound of weight
int Q;      // nb of subseq satisfy



int main(int argc, char const *argv[])
{
    cin >> n >> k >> A >> B;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << Q;
    return 0;
}
