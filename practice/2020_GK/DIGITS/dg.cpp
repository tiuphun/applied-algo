// HUST + SOICT = N
#include <iostream>
#include <algorithm>
using namespace std;

int test, N;
int x[8];           // current char we're considering (H, U, S, T, O, I, C)
bool used[10];      // keep track of assigned value
int ways = 0;

// x[0] = H, x[1] = U, x[2] = S, x[3] = T, x[4] = O; x[5] = I, x[6] = C
int check(int v, int k, int N){
    if (used[v] == 1) return 0;
    if (v == 0 && (k == 0 || k == 2 )) return 0; // H, S cannot start with zero
    if (k < 6) return 1;
    return (x[0]*1000 + x[1]*100 + x[2]*10 + x[3] + x[2]*10000 + x[4]*1000 + x[5]*100 + v*10 + x[3] == N);
//              H           U          S      T         S           O           I           C       T
// We consider when v is assigned to C since it's the last distinct digit. Before k = 7, check() always return 1 if v is not used.
}
void solution(){
    ways++;
}
void trial(int k, int N){
    for (int v = 0; v <= 9; v++) {
        if (check(v, k, N)){
            x[k] = v;
            used[v] = 1; 
            if(k == 6) solution(); // assign completed
            else trial(k+1, N);
            used[v] = 0;
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> test;
    for (int t = 0; t < test; t++) {
        cin >> N;
        ways = 0;
        trial(0, N);
        cout << ways << endl;
    }
    return 0;
}
/*
5
17868
29119
49862
78952
1000002

10
0
16
8
0
*/
