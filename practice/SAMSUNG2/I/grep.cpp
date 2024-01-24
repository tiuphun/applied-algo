#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define N 100009
int n, m, k, u, v, w;
vector<int> Head[N], Last[N];
vector<int> Adj[N];

void listArc(int w) {

}
int main(int argc, char const *argv[])
{
    ifstream inFile("grep.inp");
    ofstream outFile("grep.out");
    inFile >> n >> m >> k;
    outFile << n << m;
    for (int i = 1; i <= m; i++) {
        inFile >> u >> v;
        Adj[u].push_back(v);
    }
    int prev = 0;
    
    for (int i = 1; i <= m; i++) {
        if (Adj[i] == NULL) Head[i] = Head[i+1];
        else if (i != 1) {
            Head[i] = prev + Adj[i].size();
            prev = Head[i];
        }
        sort(Adj[i].begin(), Adj[i].end());
        Last[i] = Adj[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= Last[i].size(); j++) 
            outFile << Last[i][j];
    }
    for (int i = 1; i <= k; i++) {
        inFile >> w;
        listArc(w);
    }
    
    inFile.close();
    outFile.close();
    return 0;
}
