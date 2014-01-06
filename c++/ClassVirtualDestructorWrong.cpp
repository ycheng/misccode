#include <iostream> 
using namespace std; 

class Foo1 { 
public: 
    virtual void showV() {
        cout << "Foo1's showV" << endl; 
    } 
    ~Foo1() {
        cout << "Foo1's descructor" << endl;
    }
}; 

class Foo2 : public Foo1 { 
public: 
    virtual void showV() {
        cout << "Foo2's showV" << endl; 
    } 
    ~Foo2() {
        cout << "Foo2's descructor" << endl;
    }
}; 

void delFoo(Foo1 *foo) {
    delete foo;
}

int main() { 
    Foo2 *f2 = new Foo2(); 

    f2->showV();
    delFoo(f2);

    return 0;
}
