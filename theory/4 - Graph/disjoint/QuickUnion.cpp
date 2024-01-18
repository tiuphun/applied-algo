// Quick union implementation of Disjoint Set
#include <iostream>
using namespace std;

class QuickUnion {
private:
    vector<int> root;
public:
    QuickUnion(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }
    int find(int x) {           // cây rễ chùm
        while (x != root[x])    // traverse all the way up the root
            x = root[x];        // connect to the root (path compression)
        return x;
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) root[rootY] = rootX;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main(int argc, char const *argv[])
{
    cout << boolalpha;
    QuickUnion qu(10);
    qu.unionSet(1, 2);
    cout << qu.connected(1, 2) << endl;
    return 0;
}
