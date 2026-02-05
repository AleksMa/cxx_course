// "Hello :-) there :) 🙂 !!!" -> "Hello  there   !!!"

#include <cassert>
#include <iostream>
#include <string>

void remove_smiles(std::string& s) {
    // Write your code here
}

int main() {
    std::string s = "Hello :-) there :) 🙂 !!!";
    remove_smiles(s);

    assert(s == "Hello  there   !!!");
    return 0;
}
