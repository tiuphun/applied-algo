#include <iostream>
#include <cstring>
using namespace std;
#define N 1001
int A[N];                    // input array
int n;                          // number of elements
int res;                        // result   
int iMem[N];                 // memory array
bool bMark[N];               // mark array

int MaxSubSeqDP(int a[], int size) {
    int max_so_far = a[0];
    int cur_max = a[0];
    for (int i = 1; i < size; i++) {
        cur_max = max(a[i], cur_max + a[i]);
        max_so_far = max(max_so_far, cur_max);
    }
    return max_so_far;
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    
    return 0;
}
