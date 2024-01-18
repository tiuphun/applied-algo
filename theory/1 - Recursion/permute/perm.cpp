#include <iostream>
using namespace std;

// list out permutation that does not have 3-nb increasing sequence
bool is_cand(int i, int k) {
	if (k <= 2) return true;
	if (x[k-2] > x[k-1]) return true;
	return i < x[k-1]; // else when x[k-2] < x[k-1]
}

void TRY(int k) {
	for (int i = 1; i <= n; i++) {
		if (!marked[i]) {
			x[k] = i;
			marked[i] = true;
			if (k == n) print_sol();
			else TRY (k+1);
			marked[i] = false;
		}
	}
}
