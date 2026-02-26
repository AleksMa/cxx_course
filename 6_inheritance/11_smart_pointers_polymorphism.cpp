#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Task {
public:
    virtual ~Task() {
        std::cout << "~Task()\n";
    }
    virtual void execute() = 0;
};

class PrintTask : public Task {
    std::string msg;
public:
    virtual ~PrintTask() {
        std::cout << "~PrintTask()\n";
    }
    explicit PrintTask(std::string m) : msg(std::move(m)) {}
    void execute() override { std::cout << msg << "\n"; }
};

int main() {
    // Task* badT = new PrintTask("Hello from badTask");
    // badT->execute();

    // std::shared_ptr<Task> t(new PrintTask("Hello from Task"));
    // t->execute();

    // std::unique_ptr<Task> t(new PrintTask("Hello from Task"));
    // t->execute();

    // t = std::make_unique<PrintTask>("Hello from Task2");
    // t->execute();

    std::shared_ptr<Task> shp(new PrintTask("Hello from Task"));
    // std::shared_ptr<Task> shp2 = shp;
    shp->execute();

    shp = std::make_shared<PrintTask>("Hello from Task2");
    // shp2->execute();
    shp->execute();

    //            s3
    //             |
    // s1 -> [shared task] <- s2


}
