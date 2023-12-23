#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[3] = {0, 1, 2};
    int b[2];
    a.copy(0, 1, b);
    for (int i = 0; i < 2; i++) printf("%d ", b[i]);
    return 0;
}

