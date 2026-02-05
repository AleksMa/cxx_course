#include <iostream>
#include <string>

class UserName {
    static uint64_t next_id_;

    std::string name_;
    const uint64_t id_;

    // Cached utilities
    mutable bool cached_ = false;
    mutable std::size_t cached_hash_ = 0;

public:
    explicit UserName(std::string name)
    : id_(next_id_++)
    , name_(std::move(name))
    {
    }

    std::size_t hash() const {
        if (!cached_) {
            cached_hash_ = std::hash<std::string>{}(name_);
            cached_ = true;
        }
        return cached_hash_;
    }

    const std::string& name() const {
        return name_;
    }

    uint64_t id() const {
        return id_;
    }

    // change hash.
    void set_name(std::string new_name) {
        name_ = std::move(new_name);
        cached_ = false;
    }
};

uint64_t UserName::next_id_ = 0;

int main() {
    const UserName u("Alice");
    const UserName v("Bob");
    const UserName w("Catherine");

    std::cout << u.name() << " id=" << u.id() << " hash=" << u.hash() << "\n";
    std::cout << u.name() << " id=" << u.id() << " hash=" << u.hash() << "\n";
    std::cout << v.name() << " id=" << v.id() << " hash=" << v.hash() << "\n";
    std::cout << w.name() << " id=" << w.id() << " hash=" << w.hash() << "\n";

    return 0;
}
