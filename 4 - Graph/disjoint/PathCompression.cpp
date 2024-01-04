// Path compression optimization implementation
#include <iostream>
using namespace std;
class PathCompression {
private:
    vector<int> root;
public:
    PathCompression(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }
    int find(int x) {
        if (x == root[x]) return x;
        return root[x] = find(root[x]); // path compress using recursion
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            root[rootY] = rootX;
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main(int argc, char const *argv[])
{
    cout << boolalpha;
    PathCompression pc(10);
    pc.unionSet(1, 2);
    cout << pc.connected(1, 3) << endl;
    return 0;
}
