#include <iostream>
#include <stdexcept>

struct Operation {
    virtual ~Operation() = default;

    int apply(int x) { // non virtual!
        if (x < 0) throw std::invalid_argument("x must be non-negative");
        std::cout << "[Operation] before\n";
        int y = doApply(x);
        std::cout << "[Operation] after\n";
        return y;
    }

protected:
    virtual int doApply(int x) = 0;
};

struct Add5 : Operation {
protected:
    int doApply(int x) override { return x + 5; }
};

int main() {
    Add5 op;
    std::cout << op.apply(10) << "\n";
}
