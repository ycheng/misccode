
#include <iostream>

class Foo
{
private:
    int m_base;
    int m_value;
public:
    Foo()
    {
        // code to do A
        m_base = 10;
    }
 
    Foo(int value): Foo() // use Foo() default constructor to do A
    {
        // code to do B
        m_value = value;
    }
    void show() {
        std::cout << m_base << std::endl;
        std::cout << m_value << std::endl;
    }
};

int
main() {
    Foo foo(5);
    foo.show();

}