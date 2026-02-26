#include <iostream>
#include <string>

template <class Derived>
class TraceMixin {
protected:
    void trace(const std::string& msg) const {
        std::cout << "[" << static_cast<const Derived*>(this)->tag() << "] " << msg << "\n";
    }
};

class Worker : public TraceMixin<Worker> {
public:
    const char* tag() const { return "Worker"; }

    void run() {
        trace("start");
        trace("doing something");
        trace("finish");
    }
};

int main() {
    Worker w;
    w.run();
}
