#include <iostream>
using namespace std;
#define N 100009
int T, n, a[N];
int main(int argc, char const *argv[])
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
    }
    return 0;
}

/*
1
6
3 1 2 5 4 3

36
*/