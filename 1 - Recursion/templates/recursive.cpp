// Recursive procedures
#include <iostream>
using namespace std;
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int C(int k, int n) {
    if (k == n || k == 0) return 1;
    return C(k-1, n-1) + C(k, n-1);
}