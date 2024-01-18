#include <iostream>
using namespace std;
#define N 100009
int cnt = 1;    // initial, whole sub sq is counted as 1
int n, a[N];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[i-1]) cnt++;
    }
    cout << cnt;
    
    return 0;
}
/*
6
3 6 1 7 8 2

3
*/