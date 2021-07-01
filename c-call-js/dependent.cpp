

#include <emscripten.h>
#include <iostream>

using namespace std;

extern "C" {
    extern int custom_add(int x, int y);
}

int main(int argc, char **argv) {
    int x = 8, y = 10;
    cout << custom_add(x,y) << endl;
    return 0;
}

