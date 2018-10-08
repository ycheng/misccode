#include <iostream>
#include <vector>


int main() {
    std::vector<int> array {1, 2, 3};
    std::cout << "Hello World !" << std::endl;
    array.resize(5);
    for(auto v: array) {
        std::cout << v << std::endl;
    }

    std::cout << "Done !" << std::endl;
}