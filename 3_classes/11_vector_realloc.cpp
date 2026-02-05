// 21_vector_invalidation.cpp
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }


    std::vector<int> v;
    v.reserve(4);

    std::cout << "reserve(4): size=" << v.size() << " capacity=" << v.capacity() << "\n";

    v.push_back(1);
    v.push_back(2);

    int* p = &v[0];
    std::cout << "Before push: p=" << static_cast<void*>(p) << " *p=" << *p << "\n";

    v.push_back(3);
    v.push_back(4);
    // v.push_back(5);

    std::cout << "After pushes: &v[0]=" << static_cast<void*>(&v[0]) << " v[0]=" << v[0] << "\n";
    std::cout << "p still points to: " << static_cast<void*>(p) << " (may be invalid if reallocated)\n\n";

    std::vector<int> a;
    a.reserve(10);
    std::cout << "reserve(10): size=" << a.size() << " capacity=" << a.capacity() << "\n";

    a.resize(5);
    std::cout << "resize(5): size=" << a.size() << " capacity=" << a.capacity() << "\n";
    std::cout << "elements: ";
    for (int x : a) std::cout << x << " "; // нули
    std::cout << "\n";

    a.resize(2);
    std::cout << "resize(2): size=" << a.size() << " capacity=" << a.capacity() << "\n";

    return 0;
}
