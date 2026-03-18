#include "text_formatter.h"
#include <sstream>

std::string make_greeting_report(const std::string& name, int age) {

    std::ostringstream out;

    out << "User report\n";
    out << "-----------\n";
    out << "Name: " << name << "\n";
    out << "Age: " << age << "\n";

    return out.str();
}
