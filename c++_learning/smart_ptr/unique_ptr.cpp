
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
};
 
int main()
{
    std::unique_ptr<Resource> res(new Resource);
 
    if (res) { // use implicit cast to bool to ensure res contains a Resource
        std::cout << *res; // print the Resource that res is owning
        res->show();
    }
 
    return 0;
}
