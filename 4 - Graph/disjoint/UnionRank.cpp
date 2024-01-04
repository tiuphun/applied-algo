// Union by Rank
#include <iostream>
using namespace std;

class UnionRank{
private:
    vector<int> root;
    vector<int> rank;   // keep track of depth
public:
    UnionRank(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) {
        while (x != root[x]) 
            x = root[x];
        return x;
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX > rank[rootY]]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
int main(int argc, char const *argv[])
{
    cout << boolalpha;
    UnionRank ur(10);
    ur.unionSet(1, 2);
    cout << ur.connected(1, 2) << endl;
    return 0;
}
