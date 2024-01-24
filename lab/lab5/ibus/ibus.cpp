#include <iostream>
using namespace std;
#define N 5000
int n;              // nb of cities (1 <= n <= 500)
int m;              // nb of edges (1 <= m <= 10000)
int C[N];           // cost to get on the bus from point i (uniform for all j s.t. i -> j)
int D[N];           // max nb. of cities to travel thru from i

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> C[i] >> D[i];
    for (int i = 0; i < m; i++) 
    return 0;
}
