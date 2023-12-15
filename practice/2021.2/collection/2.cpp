/* Perform Insertion and Delete-Max on a Collection
a[1], a[2],..., a[n]
Queries:
* insert x: adding an element x to collection
* delete-max: delete from collection and return the value of max element
*/
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
#define N 100000;
int n;                              // nb of elements
priority_queue<int> a;              // the collection (max heap implementation)
string input;                       // user input
int x;
void insert(int x) {
    a.push(x);
}

int delete_max() {
    int max = a.top();
    a.pop();
    return max;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push(temp);
    }
    cin.ignore();

    while (getline(cin, input) && input != "*") {
        istringstream iss(input);
        string cmd;
        iss >> cmd;
        if (cmd == "insert") {
            iss >> x;
            insert(x);
        } else if (cmd == "delete-max") {
            cout << delete_max() << endl;
        }
    }
    return 0;
}
