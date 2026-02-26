#include <iostream>
#include <memory>
#include <vector>
#include <string>

class IOperation {
public:
    virtual ~IOperation() = default;
    virtual std::string name() const = 0;
    virtual int apply(int x) const = 0;
};

class Add : public IOperation
{
    int delta_;
public:
    explicit Add(int d) : delta_(d) {}
    std::string name() const override { return "Add(" + std::to_string(delta_) + ")"; }
    int apply(int x) const override { return x + delta_; }
};

class Multiply : public IOperation {
    int k_;
public:
    explicit Multiply(int k) : k_(k) {}
    std::string name() const override { return "Multiply(" + std::to_string(k_) + ")"; }
    int apply(int x) const override { return x * k_; }
};

int main() {
    std::vector<IOperation*> ops;
    Add add(5);
    ops.push_back(&add);
    ops.push_back(new Multiply(3));


    int x = 10;
    for (const IOperation* op : ops) {
        std::cout << op->name() << ": " << x << " -> ";
        x = op->apply(x);
        std::cout << x << "\n";
    }
}
