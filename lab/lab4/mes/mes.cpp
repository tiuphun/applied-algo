#include <iostream>
#include <vector>
using namespace std;
#define N 1000001
int n;                  // nb of elements
int a[N];               // the sequence
int b0[N];      // marking arr, existence of even sum
int b1[N];      // marking arr, existence of odd sum
int S0[N];      // even sum
int S1[N];      // odd sum

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        b0[i] = 0;
        b1[i] = 0;
    }
}

bool isEven(int a) {
    return ((a & 1) == 0);
}
bool isOdd(int a) {
    return ((a & 1) == 1);
}

int MES() {
    if (isEven(a[0])) {
        S0[0] = a[0]; b0[0] = 1;
    } else {
        S1[0] = a[0]; b1[0] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (isEven(a[i])) {
            if (b0[i-1] == 1 && S0[i-1] + a[i] > 0) {
                S0[i] = a[i] + S0[i-1];
                b0[i] = 1;
            }
            if (b1[i-1] == 1 && S1[i-1] + a[i] > 0) {
                S1[i] = a[i] + S1[i-1];
                b1[i] = 1;
            }
        }
        else if (isOdd(a[i])) {
            if (b1[i-1] == 1 && S1[i-1] + a[i] > 0) {
                S0[i] = a[i] + S1[i-1];
                b0[i] = 1;
            }
            if (b0[i-1] == 1 && S0[i-1] + a[i] > 0) {
                S1[i] = a[i] + S0[i-1];
                b1[i] = 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (S0[i] > max) max = S0[i];
    }
    return max;
}

int main(int argc, char const *argv[]) {
    input();
    int result = MES();
    cout << result;
    return 0;
}

/*
8
4 -5 2 4 -8 2 3 1
6
*/