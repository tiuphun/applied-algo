#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define N 100009
int T, n, totalTime = 0;
queue<int> group, temp;
int main(int argc, char const *argv[])
{
    cin >> T;
    int a;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            group.push(a);
        }
        int sz;
        int firstGroup, secondGroup, time, lastGroup, maxTime = 0;
        for (int i = 1; i <= ceil(n / 2.0); i++) {
            sz = group.size();
            maxTime = 0;
            while (sz > 1) {
                // Merge group by pairs
                firstGroup = group.front(); group.pop();
                secondGroup = group.front(); group.pop();
                time = firstGroup + secondGroup;
                if (maxTime < time) maxTime = time;
                temp.push(time);
                sz -= 2;
            }
            if (!group.empty()) {
                lastGroup = group.back();
                if (maxTime < lastGroup) maxTime = lastGroup;
                group.pop();
                temp.push(lastGroup);
            }
            totalTime += maxTime;

            // Update original queue
            swap(group, temp); 
        }
        cout << totalTime << endl;  
    }  
    return 0;
}

/*
1
6
3 1 2 5 4 3

36
*/