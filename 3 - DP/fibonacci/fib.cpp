#include <iostream>
#include <map>
using namespace std;
int n;

// Recursion, no memory
int fib(int n) {
    if (n <= 2) return 1;
    int res = fib(n-2) + fib(n-1);
    return res;
}

// Recursion w/ memory, using map structure (O(log n) retrieval)
map<int, int> Mem;
int mapfib(int n) {
    if (n <= 2)                     return 1;
    if (Mem.find(n) != Mem.end())   return Mem[n];
    int res = mapfib(n-2) + mapfib(n-1);
    Mem[n] = res;
    return res;
}

// Recursion w/ memory, using array structure (O(1) retrieval)

int iMem[1001];

int arrfib(int n) {
    if (n <= 2)         return 1;
    if (iMem[n] != -1)  return iMem[n];
    int res = arrfib(n-2) + arrfib(n-1);
    iMem[n] = res;
    return res;
}

int main(int argc, char const *argv[])
{
    printf("n = ");
    cin >> n;
    for (int i = 1; i <= 1000; i++)
        iMem[i] = -1;                   // for mapfib(n)
    printf("The %d-th number in Fibonacci sequence\n", n);
    printf("fib(n)\t\tmapfib(n)\tarrfib(n)\t\n");
    cout << fib(n) << "\t\t" << mapfib(n) << "\t\t" << arrfib(n) << "\n";
    return 0;
}
