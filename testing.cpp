#include "./mathLib.hpp"

int main() {
    Vektor2 a{2,6};

    std::cout << a(1) << std::endl;

    a(1) = 42;

    std::cout << a(1) << std::endl;
}