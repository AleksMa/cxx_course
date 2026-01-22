// Defined behavior: стандарт гарантирует результат.
// Undefined behavior (UB): стандарт ничего не обещает.
// Unspecified: результат из набора вариантов, но программа корректна.
// Implementation-defined: зависит от компилятора/платформы, но задокументировано.

#include <iostream>

int main() {
    int a[3] = {10, 20, 30};
    std::cout << a[3] << "\n"; // UB
}
