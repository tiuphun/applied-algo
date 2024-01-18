#include <iostream>
#include <stack>
#include <queue>

using namespace std;
queue<int> hall;
stack<int> cage, temp;
int n, d;
string s;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d;
        temp.push(d);
    }
    while (!temp.empty()) {
        cage.push(temp.top());
        temp.pop();
    }
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'C' && !cage.empty()) {
            int dino = cage.top();
            hall.push(dino);
            cage.pop();
        }
        else if (s[i] == 'H' && !hall.empty()) { 
            int dino = hall.front();
            cage.push(dino);
            hall.pop();
        }
    }

    while (!cage.empty()) {
        int top = cage.top();
        cout << top << " ";
        cage.pop();
    }
    return 0;
}

/*
4
3 1 4 2
CCHCCHHH

4 3 1 2 */