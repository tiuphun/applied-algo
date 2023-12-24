/* Ex 4. Max Sub Sequence, no 3 adjacent elements selected
Given a[1], a[2], ... a[n]
subset, max sum, does not contains 3 adj elements 

Input: 
[1] n (1 <= n <= 10^5)
[2] a1, a2, ... an (1 <= a[i] <= 10^3)

Output:
[1] sum of subseq

7 
4 10 6 6 6 2 5

31
*/

#include <iostream>
using namespace std;
#define N 100000
int n;              // nb of elements
int a[N];           // the sequence
int s[N];           // solution of subprob

int MaxSub() {
    if (n <= 2) return max(a[0], a[1]);
    if (n == 3) return max(max(a[0], a[1]), a[2]);
    s[0] = a[0]; 
    s[1] = a[0] + a[1]; 
    s[2] = max(max(a[0] + a[1], a[1] + a[2]), a[0] + a[2]);
    for (int i = 3; i < n; i++) 
        s[i] = max(max(s[i-1], s[i-2] + a[i]), s[i-3] + a[i-1] + a[i]);
    return s[n-1];
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << MaxSub();
    return 0;
}
