// Recursion and Memorization
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

class ckn {
    private:
        int M[100][100];
    public:
        int C(int k, int n) {
            if (k == 0 || k == n) M[k][n] = 1;
            else if (M[k][n] < 0) {
                M[k][n] = C(k-1, n-1) + C(k, n-1);
            }
            return M[k][n];
        }
        void test() {
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j <= i; j++) 
                    M[j][i] = -1;
            }
        cout << C(15, 30) << endl;
    }
};

int main() {
    ckn obj;
    obj.test();
    return 0;
}