#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 100
int n;
int x[N];                       // in col i, x[i] is the row in which the queen is placed
bool candidate(int v, int i) {  // v is the new value to assign to x[i]
    for (int j = 1; j <= i-1; j++) {
        if (x[j] == v) return false;
        if (abs(x[j] - v) == abs(i - j)) return false;
    }
    return true;
}

void solution() {
    for (int i = 1; i<= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}
void TRY(int i) {
    for (int v = 1; v <= n; v++) {
        if (candidate(v, i)) {
            x[i] = v;
            if (i == n) solution();
            else TRY(i+1);
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n;
    TRY(1);
    return 0;
}
