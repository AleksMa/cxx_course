#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    const int* p1 = &x;
    p1 = &y;
    // *p1 = 30;
    int* const p2 = &x;
    *p2 = 30;
    // p2 = &y;
    const int* const p3 = &x;
}
