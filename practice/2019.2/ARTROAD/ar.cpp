#include <iostream>
#include <queue>
using namespace std;
#define N 5009
int n, K;
int l, r;                       // range of arts for each artist
int nbArt[N];                   // nb of art each artist can paint
int maxArt = 0;                 // max num of art can be painted
priority_queue<int, vector<int>, greater<int> > artist;  // min heap  
// Keep track of artists with most nb of art
vector<int> artCount(N, 0);

int main(int argc, char const *argv[])
{
    cin >> n >> K;
    for (int i = 1; i <= K; i++) {
        cin >> l >> r;
        nbArt[i] = r - l + 1;
        for (int j = l; j <= r; j++) artCount[j]++;
        cout << nbArt[i] << endl;
    }
    for (int i = 1; i <= K; i++) {
        if (artist.size() < K-2) {
            artist.push(nbArt[i]);
        }
        else if (nbArt[i] > artist.top()) {
            artist.pop();
            artist.push(nbArt[i]);
        }
    }
    while (!artist.empty()) {
        maxArt += artist.top();
        artist.pop();
    }
    cout << maxArt << endl;
    return 0;
}
/*
4 3
1 1 
2 2
3 4

2

4 4
1 1 
2 2
2 3
3 4

3   // does not handle same painting by multiple artist yet
*/