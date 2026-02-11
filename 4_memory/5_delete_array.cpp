#include <iostream>

struct Item {
    int id;

    Item(int id_) : id(id_) {
        std::cout << "ctor " << id << "\n";
    }

    ~Item() {
        std::cout << "dtor " << id << "\n";
    }
};

void delete_array(Item* p) {
    std::cout << "delete_array(): calling delete[]\n";
    delete[] p;
}

int main() {
    std::cout << "=== CASE 1: size is known here ===\n";
    {
        Item* a = new Item[3]{ Item(1), Item(2), Item(3) };

        std::cout << "main(): calling delete[]\n";
        delete[] a;
    }

    std::cout << "\n=== CASE 2: size is lost (only Item*) ===\n";
    {
        Item* b = new Item[4]{Item(10), Item(20), Item(30), Item(40)};

        delete_array(b);
    }
}
