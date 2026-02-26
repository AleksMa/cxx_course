#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& msg) const {
        std::cout << "[log] " << msg << "\n";
    }
};

class LoudLogger : public Logger {
public:
    void shout(const std::string& msg) const {
        log("!!! " + msg + " !!!");
    }
    // log
};

class InternalLog : private Logger {
public:
    void doWork() {
        log("work started");
        log("work finished");
    }

    using Logger::log;
};

void takesLogger(const Logger& l) {
    l.log("hello from takesLogger()");
}

int main() {
    Logger l;
    l.log("hello from main()");

    LoudLogger a;
    a.log("public inheritance keeps interface");
    a.shout("louder");

    takesLogger(a);

    InternalLog b;
    b.doWork();
    b.log("we selectively exposed log()");
    // takesLogger(b);
}