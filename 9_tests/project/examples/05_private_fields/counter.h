#pragma once

#include <stdexcept>

class CounterTest_CanReadPrivateValue_Test;

class Counter {
public:
    void increment() {
        ++value_;
    }

    void decrement() {
        if (value_ == 0) {
            throw std::runtime_error("counter is already zero");
        }
        --value_;
    }

    int value() const {
        return value_;
    }

private:
    int value_ = 0;

    friend class CounterTest_CanReadPrivateValue_Test;
};
