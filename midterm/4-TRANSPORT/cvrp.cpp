#include <iostream>
using namespace std;
#define N 20
int n;              // nb of customers (also position index)
int K;              // nb of trucks
int Q;              // capacity
int d[N];           // customer request
int c[N][N];        // cost matrix
int M;              // nb of conflict pairs
pair<int, int> F;   // conflict



int main(int argc, char const *argv[])
{
    cin >> n >> K >> Q;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    }
    cin >> M;
    for (int i = 0; i < M; i++) cin >> F.first >> F.second;
    return 0;
}
