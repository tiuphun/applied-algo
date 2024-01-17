#include <iostream>
#include <algorithm>
using namespace std;
#define N 20
#define M 200
int n;                  // nb of customers (also position index)
int K;                  // nb of trucks
int Q;                  // capacity
int d[N];               // customer request
int c[N][N];            // cost matrix
int m;                  // nb of conflict pairs
pair<int, int> F[M];    // conflict

vector<vector<int> > routes;
bool served[N];
int load;

void generateRoutes(int truck, int load, vector<int> route, bool served) {
    if (load == Q || all customer served) {
        routes[truck].push_back(route);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (served[i] == false && customer i not in conflict) {
            route.push_back(i);
            load += d[i];
            served[i] = true;
            generateRoutes(truck, load, route, served);
            route.pop_back();
            load -= d[i];
            served[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> K >> Q;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    }
    cin >> m;
    for (int i = 0; i < m; i++) cin >> F.first >> F.second;
    
    int minCost = INT_MAX;
    bool solutionFound = false;
    fill_n(served, n, false);

    for (int i = 0; i < K; i++) {
        generateRoutes(i, 0, {}, served);
    }
    for (const auto& truckRoutes : routes) {
        for (const auto& route: truck)
    }



    return 0;
}
