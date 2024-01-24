#include <iostream>
#include <vector>
using namespace std;
#define N 1000009
int n, m, x, y, t;
int num[N], low[N], child[N];
int ap[N], p[N];
vector<int> Adj[N];
void DFS(int u) {
    t++;
    num[u] = t;
    low[u] = num[u];
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if (v == p[u]) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            p[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        Adj[x].push_back(y);
        Adj[y].push_back(x);
    }

    int ansAP = 0, ansBridge = 0;
    t = 0;
    for (int i = 1; i <= n; i++) {
        if (!num[i]) DFS(i);
    }
    for (int i = 1; i <= n; i++) {
        int u = p[i];
        if (u > 0 && p[u] > 0 && low[i] >= num[u]) ap[u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0 && child[i] >= 2) ap[i] = 1;
    }
    for (int i = 1; i <= n; i++) ansAP += ap[i] == 1;
    for (int i = 1; i <= n; i++) {
        if (p[i] != 0 && low[i] >= num[i]) ++ansBridge;
    }
    cout << ansAP << " " << ansBridge << endl;
    return 0;
}
