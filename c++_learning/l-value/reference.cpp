#include <iostream>
#include <string>
#include <vector>
 
class Fraction
{
private:
	int m_numerator;
	int m_denominator;
 
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
		std::cout << "Fraction constructor\n";
	}

	Fraction(Fraction&& o) :
		m_numerator(o.m_numerator), m_denominator(o.m_denominator)
	{
		std::cout << "Fraction move constructor\n";
	}

    ~Fraction() {
        std::cout << "~Fraction\n";
    }
 
	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
};
 
int demo_rvalue()
{
	Fraction &&rref = Fraction(3, 5); // r-value reference to temporary Fraction
	std::cout << rref << '\n';
 
	return 0;
} // rref (and the temporary Fraction) goes out of scope here


void
demo_move() {
	/*
    Fraction a = Fraction(1,2);
    Fraction b = Fraction(2,3);
	// std::cout << a << std::endl;
    Fraction t { std::move(a) };
	a = std::move(b);
	b = std::move(t);
    // std::cout << b << std::endl;
	*/
}

void
demo_move2()
{

	std::vector<std::string> v;
	std::string s { "hello world 1\n" };
	std::cout << s;

	v.push_back(std::string("hello world 2\n")); // move possible, as string is an rvalue (and 
                                    // std::string implements move semantics)
	v.emplace_back("hello world 3\n"); // just illustrating how we do the same the less-verbose C++11 way
	v.push_back(s);                // move can't be done, as parameter is an rvalue
	v.push_back(std::move(s));     // move possible, as we're explicitly moving the data out of s, 
                               	   // making s now be empty
	std::cout << "===" << s << "===" << std::endl; // Empty !!
	std::cout << "-----\n";
	for (auto v: s) {
		std::cout << v;
	}
}

int
main() {
    demo_rvalue();
    demo_move2();
}