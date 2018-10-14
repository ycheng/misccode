
// c++11
// ref: https://thispointer.com/c11-variadic-template-function-tutorial-examples/

#include <iostream>

// Function that accepts no parameter
// It is to break the recursion chain of vardiac template function
void log()
{
    std::cout << std::endl;
}
 
/*
 * Variadic Template Function that accepts variable number
 * of arguments of any type.
 */
template<typename T, typename ... Args>
void log(T first, Args ... args) {
 
	// Print the First Element
	std::cout<<first<<", ";
 
	// Forward the remaining arguments
	log(args ...);
}
 
 
int main() {
	log(2, 3.4, "aaa");
    // current output "2, 3.4, aaa,"
    // TODO: how to output "2, 3.4, aaa"
	return 0;
}