#include <iostream>
#include <memory>
#include <vector>
#include <string>

struct Task {
    virtual ~Task() = default;
    virtual void execute() = 0;
};

struct PrintTask : Task {
    std::string msg;
    explicit PrintTask(std::string m) : msg(std::move(m)) {}
    void execute() override { std::cout << msg << "\n"; }
};

struct FakeHandle {
    int id;
};

static FakeHandle* acquireHandle(int id) {
    std::cout << "acquire handle " << id << "\n";
    return new FakeHandle{id};
}

static void releaseHandle(FakeHandle* h) {
    std::cout << "release handle " << h->id << "\n";
    delete h;
}

int main() {
    std::unique_ptr<Task> t = std::make_unique<PrintTask>("Hello from Task");
    t->execute();

    auto s1 = std::make_shared<PrintTask>("shared task");
    std::shared_ptr<Task> s2 = s1;
    s1->execute();
    s2->execute();
    std::cout << "use_count = " << s1.use_count() << "\n\n";

    std::shared_ptr<FakeHandle> h(
        acquireHandle(42),
        [](FakeHandle* p) { releaseHandle(p); }
    );

    std::cout << "handle id = " << h->id << "\n";
}
