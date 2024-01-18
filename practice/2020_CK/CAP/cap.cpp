#include <iostream>
using namespace std;
#define N 109
int T;
int n, m;
int a[N], b[N];
int main(int argc, char const *argv[])
{
    cin >> T;
    for (int t = 0; t < T; t++) {
        int count = 0;
        cin >> n;   
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == n) count++;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            if (b[i] == n) count++;
        }
        cout << count;
    }

    return 0;
}
/*
1
4
2 1 4 3
3 
1 5 4

2
*/