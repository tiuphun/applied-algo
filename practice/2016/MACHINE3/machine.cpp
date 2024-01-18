#include <iostream>
using namespace std;
#define N 1000009
int n, k;
pair<int, int> T[N];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> T[i].first >> T[i].second;

    int lastEndT = -1;
    int C = 0;
    sort(T + 1, T + n + 1, compare);
    for (int i = 1; i <= n; i++) {
        if (T[i].first > lastEndT) {
            C = C + T[i].second - T[i].first;
            lastEndT = T[i].second;
        }
    }
    cout << C << endl;
    return 0;
}
// (Solved with greedy & EFT)
/*
5 2
8 12
6 11
3 9
2 5
1 4

8
*/