#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

struct ITool {
    virtual ~ITool() = default;
    virtual std::string name() const = 0;
    virtual void run() const = 0;
};

struct Hammer : ITool {
    std::string name() const override { return "Hammer"; }
    void run() const override { std::cout << "Bang bang!\n"; }
};

struct Brush : ITool {
    std::string name() const override { return "Brush"; }
    void run() const override { std::cout << "Swish swish!\n"; }
};

std::unique_ptr<ITool> makeTool(const std::string& type) {
    if (type == "hammer") {
        return std::make_unique<Hammer>();
    }
    if (type == "brush") {
        return std::make_unique<Brush>();
    }
    throw std::runtime_error("Unknown ITool type: " + type);
}

int main() {
    for (const std::string type : {"hammer", "brush"}) {
        std::unique_ptr<ITool> t = makeTool(type);
        std::cout << "Created: " << t->name() << "\n";
        t->run();
    }

    // auto bad = makeTool("saw");
}