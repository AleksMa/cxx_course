#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::out_of_range("Out of range");
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << "\n";
    } catch (const std::logic_error& e) {
        std::cout << "Logic: " << e.what() << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Runtime: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Generic: " << e.what() << "\n";
    } catch (...) {
        std::cout << "Caught\n";
    } 
}
