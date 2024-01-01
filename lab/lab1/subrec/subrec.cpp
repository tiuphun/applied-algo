// Done
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int N = 1e3 + 1;
int a[N][N];                // the matrix
int n;                      // number of rows
int m;                      // number of columns
int ans;                                
long long h[N];             // height of the histogram
stack<long long> S;         // stack for computing the histogram
vector<long long> V;        // vector for computing the histogram
long long L[N], R[N];       // left and right boundaries of the histogram

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
}
long long compute() {
    h[0] = -1;
    h[m+1] = -1;
    V.clear();
    for (int i = 1; i <= m+1; i++)
    {
        while (!V.empty() && h[i] < h[V[V.size()-1]])
        {
            R[V[V.size()-1]] = i;
            V.pop_back();
        }
        V.push_back(i);
    }
    for (int i = m; i >= 0; i--)
    {
        while (!V.empty() && h[i] < h[V[V.size()-1]])
        {
            L[V[V.size()-1]] = i;
            V.pop_back();
        }
        V.push_back(i);
    }
    unsigned long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        unsigned long long c = (R[i] - L[i] - 1) * h[i];
        ans = max(ans, c);
    }
    return ans;
}
void solve() {
    long long ans = 0;
    for (int i = 0; i <= m; i++) 
        h[i] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (a[i][j] == 0) 
                h[j] = 0;
            else
                h[j]++;
        }
        long long t = compute();
        if (t > ans) ans = t;
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    input();
    solve();
    return 0;
}

//SAMPLE INPUT
// 4 4
// 0 1 1 1
// 1 1 1 0
// 1 1 0 0
// 1 1 1 0
//OUTPUT
//6