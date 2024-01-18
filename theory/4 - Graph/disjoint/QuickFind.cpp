// Quick find implementation of Disjoint Set
#include <iostream>
using namespace std;

class QuickFind {
private:
    vector<int> root;
public:
    QuickFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }
    int find(int x) {       // cây rễ cọc
        return root[x];     // only connect to the direct parent
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            for (int i = 0; i < root.size(); i++) {     // quite slow
                if (root[i] == rootY) root[i] = rootX;
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
    QuickFind qf(10);
    qf.unionSet(1, 2);
    cout << qf.connected(1, 2) << endl; // Should print 1 (true)
    return 0;
}
