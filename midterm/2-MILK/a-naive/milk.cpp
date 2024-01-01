/* My original solution:
Generate binary sequence and calc sum for each permutation
*/
#include <iostream>
using namespace std;
#define N 25
int n;          // nb of secret numbers
int year;       // year the company is founded
int a[N];       // sequence of secret numbers
int ans;        // nb of ways to collect milkboxes
char s[100];    // the binary sequence

void calc(char* s, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') sum += a[i];
    }
    if (sum >= year) ans++;
}

void TRY() {
    for (int i = 0; i < n; i++) s[i] = '0';
    while (true)
    {
        calc(s, n);
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }
        if (i < 0) break;
        s[i] = '1';
    }
    
}
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> year;
    TRY();
    cout << ans;
    return 0;
}


/*
4
1000 1601 100 200
1901

5
*/