/* Ex 4. Max Subsequence, no 3 adjacent elements selected
Given a[1], a[2], ... a[n]
subset, max sum, does not contains 3 adj elements 

Input: 
[1] n (1 <= n <= 10^5)
[2] a1, a2, ... an (1 <= a[i] <= 10^3)

Output:
[1] sum of subseq
*/

#include <iostream>
using namespace std;
#define N 100000
int n;              // nb of elements
int a[N];           // the sequence
int s[N];           // solution of subprob
int ans = 0;

int MaxSub(int i) {
    if (i == 1) return a[0];
    if (i == 2) return max(a[0], a[1]);
    if (i == 3) return max(max(a[0], a[1]), a[2]);

    for (int k = 2; k <= i; k++) 
        ans = max(a[i], a[i] + MaxSub(i-k));
    return ans;
    // for (int k = 4; k < n; k++) {
    //     int j = 1; 
    //     while (j <= i-3) {
    //         s[k] = max(MaxSub(j), MaxSub(j-1));
    //         j++;
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     if (ans < s[i]) ans = s[i];
    // }
    // return ans;
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << MaxSub(n);
    return 0;
}
