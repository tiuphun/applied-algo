// Done
/*
• Given N elements (2≤ N ≤100,000) on a straight line at positions x1,…, xn (0≤ x ≤1,000,000,000)
• The distance of a subset of N elements is defined to be the minimum distance between two elements
• Find the subset of N given elements containing exactly C elements such that the distance is maximal.
• Input
• The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases.
• Subsequent lines are T test cases with the following format:
• Line 1: Two space-separated integers: N and C
• Lines 2: contains x1, x2 , . . , xn
• Output
• For each test case output one integer: the distance of the subset found.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100000
int T;                  // number of tests in test set T
int n;                  // number of elements
int c;                  // size of a subset
int a[N];               // set of points
int result;
bool check(int distance) {
    int pcount = 1;
    int i = 0, j = 1;
    while (i < n) {
        while (j < n && a[j] - a[i] < distance) ++j;
        if (j < n) pcount ++;
        if (pcount >= c) return true;
        i = j;
        j = i+1;
    }
    return false;
}
int MaxDistance() {
    int left = 0, right = a[n-1] - a[0];
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--) {
        cin >> n >> c;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        cout << MaxDistance() << endl;
    } 
    return 0;
}