#include <iostream>
#include <string>

template <class T>
struct Serializer {
    static std::string dump(const T&) {
        return "<unknown>";
    }
};

template <>
struct Serializer<int> {
    static std::string dump(const int& x) {
        return "int:" + std::to_string(x);
    }
};

template <class T>
struct Serializer<T*> {
    static std::string dump(T* p) {
        return p ? "ptr:non-null" : "ptr:null";
    }
};

int main() {
    int x = 7;
    int* p = &x;
    int* q = nullptr;

    std::cout << Serializer<double>::dump(3.14) << "\n";
    std::cout << Serializer<int>::dump(x) << "\n";
    std::cout << Serializer<int*>::dump(p) << "\n";
    std::cout << Serializer<int*>::dump(q) << "\n";
}
