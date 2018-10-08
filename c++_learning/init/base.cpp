
#include <iostream>

class Base
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value(value)
    {
    }
 
    const char* getName() { return "Base"; }
    int getValue() { return m_value; }
};


int
main()
{
    Base b(10);
    // Base b{10}; // error: not working
    std::cout << b.getValue();

}
