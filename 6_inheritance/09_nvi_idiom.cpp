#include <iostream>
#include <stdexcept>

struct IOperation {
    virtual ~IOperation() = default;

    int apply(int x) { // non virtual!
        std::cout << "[IOperation] before\n";

        int y = doApply(x);

        std::cout << "[IOperation] after\n";
        return y;
    }

protected:
    virtual int doApply(int x) = 0;
};

struct Add5 : IOperation {
protected:
    int doApply(int x) override { return x + 5; }
};

int main() {
    Add5 op;
    IOperation& iop = op;
    std::cout << iop.apply(10) << "\n";
}
