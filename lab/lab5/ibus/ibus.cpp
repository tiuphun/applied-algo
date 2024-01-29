#include <iostream>
#include <queue>
using namespace std;
#define N 5009
#define INF 1000000000
int n;              // nb of cities (1 <= n <= 500)
int m;              // nb of edges (1 <= m <= 10000)
int C[N];           // cost to get on the bus from point i (uniform for all j s.t. i -> j)
int D[N];           // max nb. of cities to travel thru from i
int w[N][N];        // weight of arc(u, v)
int d[N];           // d[i] = distance source -> i during BFS
bool f[N];          // true = shortest path s -> v found
vector<int> A[N];   // A[v] list of adj cities of v

void BFS(int i) {
    queue<int> Q;
    fill(d, d+N, -1);
    d[i] = 0; Q.push(i);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        w[i][v] = C[i]; 
        for (int j = 0; j < A[v]. size(); j++) {
            int u = A[v][j];
            if (d[u] >= 0) continue;    // u visited
            d[u] = d[v] + 1;
            if (d[u] <= D[i]) Q.push(u);
        }
    }
}
void dijkstra(int s, int t) {
    for (int v = 1; v <= n; v++) {
        d[v] = w[s][v];
        f[v] = false;
    }
    d[s] = 0; f[s] = true;
    for (int i = 1; i <= n; i++) {
        int u = -1; int minD = INF;
        // select a node u have min d[u]
        for (int v = 1; v <= n; v++) {
            if (!f[v] && d[v] < minD) {
                u = v;
                minD = d[v];
            }
        }
        f[u] = true;
        if (u == t) break;          // result found
        for (int v = 1; v <= n; v++) {
            if (!f[v] && d[v] > d[u] + w[u][v]) 
                d[v] = d[u] + w[u][v];
        }
    }
    cout << d[t];
}
void buildGraph() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            w[i][j] = INF;
    }
    for (int i = 1; i <= n; i++) BFS(i);
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> C[i] >> D[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    buildGraph();
    dijkstra(1, n);
    return 0;
}
