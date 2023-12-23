// Another improvement using Prefix Sum data structure
#include <iostream>
using namespace std;
#define N 100009
int n;      // nb of elements
int a[N];   // the sequence
int k;      // nb of elements in subseq
int A;      // lower bound of weight
int B;      // upper bound of weight
int sum;

bool inRange(int sum) {
    return (sum >= A && sum <= B);
}
void PrefixSum() {
    int count = 0;
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    for (int i = 0; i <= n-k; i++) {
        sum = prefix[i+k-1] - (i > 0 ? prefix[i-1] : 0);
        if (inRange(sum)) count++;
    }
    cout << count;
}

int main(int argc, char const *argv[])
{
    cin >> n >> k >> A >> B;
    for (int i = 0; i < n; i++) cin >> a[i];
    PrefixSum();
    return 0;
}