#include <iostream>
#include <vector>
using namespace std;
#define N 100009
int n, m, u, v, i, j;
vector<int> Adj[N];
vector<bool> visited[N];
vector<int> path;

void DFS(int u) {
    visited[u] = true;
    for (int k = 0; k < Adj[u].size(); k++) {
        if (!visited[v]) {
            visited[v] = true;
            DFS(v);
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int k = 1; k <= m; k++) {
        cin >> u >> v;
        Adj[u].push_back(v);
    }
    cin >> i >> j;

    int nbCC = 0;
    fill(visited, visited+N, false);
    for (int k = 1; k <= n; k++) {
        if (!visited[k]) {
            nbCC++;
            DFS(u);
        }
    }
    cout << nbCC << endl;

    fill(visited, visited + N, false);
    path.clear();
    path.push_back(i);
    DFS(i);
    if (visited[j]) {
        for (int k : path) {
            cout << u << " ";
            if (u == j) break;
        }
    }
    cout << endl;
    return 0;
}
