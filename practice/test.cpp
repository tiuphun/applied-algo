#include <iostream>
#include <vector>
using namespace std;

void chooseKFromN(int start, int k, vector<int>& combination, int n) {
    if (k == 0) {
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; i++) {
        combination.push_back(i);
        chooseKFromN(i + 1, k - 1, combination, n);
        combination.pop_back();
    }
}

int main() {
    int n = 5;
    int k = 3;
    vector<int> combination;
    chooseKFromN(1, k, combination, n);
    return 0;
}