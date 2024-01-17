#include <iostream>
#include <queue>
using namespace std;
#define N 5000
#define M 500000
int n, m;                               // nb of nodes, nb of edges
int e[N];                               // eccentricity arr
vector<int> adj[N];                     // edges of G, adj list
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    int i, j;
    for (int k = 0; k < m; k++) {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    
    // Calc eccentricity of u in G (BFS)
    for (int u = 1; u <= n; u++) {
        vector<int> distance(N, INT_MAX);
        vector<bool> visited(N, false);
        queue<int> Q;
        Q.push(u);
        visited[u] = true;
        distance[u] = 0;
        e[u] = 0;
        while (!Q.empty())
        {
            int cur = Q.front(); Q.pop();
            for (int i = 0; i < adj[cur].size(); i++) {
                int v = adj[cur][i];
                if (!visited[v]) {
                    Q.push(v);
                    visited[v] = true;
                    distance[v] = distance[cur] + 1;
                }
                e[u] = max(e[u], distance[v]);
            }
        }
    }

    // Calc radius of G
    int radius = INT_MAX;
    for (int i = 1; i <= n; i++) {
        radius = min(radius, e[i]);
    }

    cout << radius;
    return 0;
}

/*
5 6
1 2
1 3
1 5
2 4
2 5
3 5

2
*/