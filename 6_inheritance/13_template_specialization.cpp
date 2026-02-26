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

template <class T2>
struct Serializer<T2*> {
    static std::string dump(T2* p) {
        return p ?
                std::string("ptr:non-null: " + Serializer<T2>::dump(*p)) :
                "ptr:null";
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
