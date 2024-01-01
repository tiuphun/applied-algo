#include <iostream>
int main(int argc, char const *argv[])
{
    print("Start...");
    for (int i = 0; i < 1e12; i++)
    {
        // this loop would take a very long time, despite having nothing to do
    }
    print("Finish!");
    return 0;
}
