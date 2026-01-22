#include <iostream>
#include <limits>
#include <cstdint>

using ui64 = unsigned long long;
typedef int i32;

using error_t = std::string;

using std::cout;

int main() {
    // i32 x;
    // cout << sizeof(x) << "\n";
    // ui64 y;
    // std::cout << sizeof(y) << "\n";
    // std::cout << "sizeof(int) = " << sizeof(int) << "\n";
    // std::cout << "sizeof(long) = " << sizeof(long) << "\n";
    // std::cout << "sizeof(long long) = " << sizeof(long long) << "\n";

    // std::cout << "int min = " << std::numeric_limits<int>::min() << "\n";
    // std::cout << "int max = " << std::numeric_limits<int>::max() << "\n";

    // std::cout << "uint32_t size = " << sizeof(std::uint32_t) << "\n";
    // std::cout << "int64_t size = " << sizeof(std::int64_t) << "\n";

    double balance = 100000000 * 1e9;
    balance -= 75.;

    cout << std::fixed << balance << std::endl;

    // std::cout << "float size = " << sizeof(float) << "\n";
    // std::cout << "double size = " << sizeof(double) << "\n";
    // std::cout << "long double size = " << sizeof(long double) << "\n";
}
