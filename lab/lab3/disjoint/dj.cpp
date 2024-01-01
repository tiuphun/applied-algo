// Done
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100005
int n;          // number of time intervals
pair<int, int> T[N];
int result;

bool compare(const pair<int, int>& a, const pair <int, int>& b) {
    return a.second < b.second;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> T[i].first >> T[i].second;
}

void greedy() {
    int lastEndTime = -1;       // the endtime of last chosen segment
    int count = 0;
    sort(T + 1, T + n + 1, compare);
    for (int i = 1; i <= n; i++) {
        if (T[i].first > lastEndTime) {
            count++;
            lastEndTime = T[i].second;
        }
    }
    cout << count;
}
int main(int argc, char const *argv[])
{
    input();
    greedy();
    return 0;
}

/*
6
0 10
3 7
6 14
9 11
12 15
17 19

4
*/