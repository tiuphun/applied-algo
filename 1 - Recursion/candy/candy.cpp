#include <iostream>
using namespace std;

const int MAXN = 20;
int n;				// number of kids
int m;				// number of candies
int x[MAXN];		// x[i] = nb of candies for kid i
int cur_sum = 0;	// current sum of candies

void print_sol() {
	for (int i = 1; i <= n; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
}

void TRY(int k) {
	// x1, x2, ..., x[k-1] = cur_sum
	// x[k]: 1 .. m - cur_sum - (n-k)
	int start_val = k != n? 1 : m - cur_sum - (n-k);
	for (int i = start_val; i <= m - cur_sum - (n-k); i++) {
		// for no 2 adjacent kids getting the same nb of candies
		// remember to assign a virtual kid: x[0] = 0;
		// if (x[k-1] == i) continue;
		x[k] = i;
		cur_sum += i;
		if (k == n) print_sol();
		else TRY(k+1);
		cur_sum -= i;
	}
}

int main () {
	cur_sum = 0;
	printf("n = ");
	cin >> n;
	printf("m = ");
	cin >> m;
	TRY (1);
	return 0;
}
