// Kosaraju's algorithm
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define N 100009
#define M 1000009
int n, m, u, v, nbSCC = 0;
vector<int> Adj[N], rAdj[N];
bool visited[N];
stack<int> finishStack;

void DFS1(int node) {
    visited[node] = true;
    for (int w : Adj[node]){
        if (!visited[w]) DFS1(w);
    }
    finishStack.push(node);
}
void DFS2(int node) {
    visited[node] = true;
    for (int w : rAdj[node]) {
        if (!visited[w]) DFS2(w);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        Adj[u].push_back(v);
        rAdj[v].push_back(u);
    }
    fill(visited, visited+N, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) DFS1(i);
    }

    fill(visited, visited+N, false);
    while (!finishStack.empty()) {
        int node = finishStack.top();
        finishStack.pop();
        if (!visited[node]) {
            DFS2(node);
            nbSCC++;
        }
    }

    cout << nbSCC << endl;
    return 0;
}
