#include <iostream>
#include <vector>
#include <array>

// std::vector is a template class that encapsulate a dynamic array1,
// stored in the heap, that grows and shrinks automatically if elements
// are added or removed.
int
demo_vector() {
    std::vector<int> v {1, 2, 3};
    std::cout << "Hello World !" << std::endl;
    v.resize(5);
    for(auto val: v) {
        std::cout << val << std::endl;
    }

    std::cout << "Done !" << std::endl;
}


// std::array is a template class that encapsulate a statically-sized
// array, stored inside the object itself, which means that, if you
// instantiate the class on the stack, the array itself will be on
// the stack. Its size has to be known at compile time (it's passed
// as a template parameter), and it cannot grow or shrink.
void
demo_array() {
    std::array<int, 3> array1 {1, 2, 3};
    std::cout << "Hello World !" << std::endl;
    // array1.resize(5); // array does not support resize.
    for(auto v: array1) {
        std::cout << v << std::endl;
    }

    std::cout << "Done !" << std::endl;
}

int main() {
    demo_vector();
    demo_array();
}
