#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string s;           // name
int k;              // nb of remain chars
string ans;         // new name
vector<char> stack;

int main(int argc, char const *argv[])
{
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++) {
        while (!stack.empty() && s[i] > stack.back() && s.size() - i + stack.size() > k) {
            stack.pop_back();
        }
        if (stack.size() < k) stack.push_back(s[i]);
    }
    for (char c : stack) cout << c;
    
    return 0;
}

/*
cxabdfa
3

xfa
*/