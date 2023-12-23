/* K-combination sum is equal to m
a[1], a[2], ..., a[n]
k, m
Find Q, nb of choosing k elements s.t. their sum = m

5 3 10
1 2 3 4 5

2
*/
#include <iostream>
using namespace std;
#define N 20
int k;              // nb of elements chosen
int m;              // the sum
int a[N];           // the array
int n;              // nb of elements in array
int Q;              // nb of choices
int curSum;         // current sum   
vector<int> C;      // combination

bool check(int i) {
    return curSum + a[i] <= m;
}

void Ckn(int start, int k, vector<int> & C, int a[]) {
    if (curSum == m) Q++;
    if (k == 0) return;
    for (int i = start; i < n; i++) {
        if (check(i)) {
            C.push_back(a[i]);
            curSum += a[i];
            Ckn(i + 1, k - 1, C, a);
            C.pop_back();
            curSum -= a[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    curSum = 0;
    Q = 0;
    Ckn(0, k, C, a);
    cout << Q;
    return 0;
}
