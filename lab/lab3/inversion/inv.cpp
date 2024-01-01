// Done
/*
• Given a sequence of integers a1, a2,…, an. A pair (I, j) is called an inversion if i < j and ai > aj
• Compute the number Q of inversions
• Input
• Line 1: contains a positive integer n ( 1 <= n <= 106 )
• Line 2: contains a1, a2,…, an ( 0 <= ai <= 106 )
• Output
• Write the value Q module 109 + 7
6
3 2 4 5 6 1

6
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000006
#define MOD 1000000007
int n;
int a[N];
int temp[N];

int merge(int left, int mid, int right) {
    int i = left, j = mid+1, k = left, inv_count = 0; // k is index for temp[]
    while ((i <= mid) && (j <= right)) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            inv_count = (inv_count + (mid - i + 1)) % MOD;
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    copy(temp+left, temp+right+1, a+left);      // copy merged elements to original array
    return inv_count;
}

int mergeSort(int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count = (inv_count + mergeSort(left, mid)) % MOD;
        inv_count = (inv_count + mergeSort(mid + 1, right)) % MOD;
        inv_count = (inv_count + merge(left, mid, right)) % MOD;
    }
    return inv_count;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL); // optimization for I/O
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << mergeSort(1, n);
    return 0;
}

/// @brief A naive implementation, complexity O(n^2)
/// @return count
int naive() {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] > a[j]) count++;
        }
    }
    return count;
}