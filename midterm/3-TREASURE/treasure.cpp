#include <iostream>
using namespace std;
#define MAX 1009
int n, m;
int a[MAX][MAX];

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
    }
    return 0;
}
