#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define N 100009
#define M 1000009
int n, m, u, v, nbSCC = 0, T = 0;
vector<int> Adj[N];
int visited[N], low[N];
bool inStack[N];
stack<int> st;

void TarjanSCC(int u) {
    visited[u] = low[u] = ++T;
    st.push(u);
    inStack[u] = true;

    for (int v : Adj[u]) {
        if (visited[v] == -1) {
            TarjanSCC(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], visited[v]);
        }
    }

    if (low[u] == visited[u]) {
        nbSCC++;
        while (st.top() != u) {
            inStack[st.top()] = false;
            st.pop();
        }
        inStack[st.top()] = false;
        st.pop();
    }
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        Adj[u].push_back(v);
    }

    fill(visited, visited + N, -1);
    fill(low, low + N, -1);
    fill(inStack, inStack + N, false);

    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) {
            TarjanSCC(i);
        }
    }

    cout << nbSCC << endl;
    return 0;
}