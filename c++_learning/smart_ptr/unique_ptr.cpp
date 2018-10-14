
#include <iostream>
#include <memory> // for std::unique_ptr
 
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    friend std::ostream& operator<<(std::ostream& out, const Resource &res) {
	    out << "I am a resource\n";
	    return out;
    }
    void show() {
        std::cout << "Resouce show !" << std::endl;
    }
    void printAddress ()
    {
        std::cout << reinterpret_cast<const void*>( this ) << std::endl;
    }
};

void
demo1() {
    std::unique_ptr<Resource> res;
    auto res2(std::make_unique<Resource>());

    if (res) { // use implicit cast to bool to ensure res contains a Resource
        std::cout << "this is res\n";
        res->printAddress();
        std::cout << *res; // print the Resource that res is owning
    } else {
        std::cout << "res is empty\n";
    }
    if (res2) {
        std::cout << "this is res2\n";
        res2->printAddress();
        std::cout << *res2;
    } else {
        std::cout << "ress is empty\n";
    }

    res = std::move(res2);
    std::cout << "=======> move res2 to res\n";

    if (res) { // use implicit cast to bool to ensure res contains a Resource
        std::cout << "this is res\n";
        res->printAddress();
        std::cout << *res; // print the Resource that res is owning
    } else {
        std::cout << "res is empty\n";
    }
    if (res2) {
        std::cout << "this is res2\n";
        res2->printAddress();
        std::cout << res2;
    } else {
        std::cout << "res2 is empty\n";
    }
}

int main()
{
    demo1(); 
    return 0;
}
