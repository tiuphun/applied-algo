#include <iostream>
using namespace std;
#define N 1009
int n;
int a[N];
int totalPhoto = 0;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int j, k;
    for (int i = 0; i < n; ) {
        j = i+1, k = i+2;
        if (k < n && a[k] - a[i] <= 10) {
            totalPhoto += 1;
            i = k+1; 
        }
        else if (j < n && a[j] - a[i] <= 20) {
            totalPhoto += 1;
            i = j+1; 
        }
        else {
            totalPhoto += 1;
            i++;
        }
    }
    cout << totalPhoto << endl;
    return 0;
}