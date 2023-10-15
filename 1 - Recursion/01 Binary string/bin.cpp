#include <iostream>
using namespace std;
char s[100];
int n;
void print_sol() {
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
}

void TRY() {
    for (int i = 0; i < n; i++) {
        s[i] = '0';
    }
    while (true) {
        print_sol(s, n);
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }
        if (i < 0) {
            break;
        }
        s[i] = '1';
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    TRY();
    return 0;
}
