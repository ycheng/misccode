#include <iostream> 
using namespace std; 

class Foo1 { 
public: 
    void showR() {
        cout << "Foo1's showR" << endl; 
    } 
    virtual void showV() {
        cout << "Foo1's showV" << endl; 
    } 
    virtual void showV2() {
        cout << "Foo1's showV2" << endl; 
    } 
    void showV3() {
        cout << "Foo1's showV3" << endl; 
    } 
    virtual ~Foo1() {
        cout << "Foo1's descructor" << endl;
    }
}; 

class Foo2 : public Foo1 { 
public: 
    void showR() {
        cout << "Foo2's showR" << endl; 
    } 
    virtual void showV() {
        cout << "Foo2's showV" << endl; 
    } 
    void showV2() {
        cout << "Foo2's showV2" << endl; 
    } 
    virtual void showV3() {
        cout << "Foo2's showV3" << endl; 
    } 
    virtual ~Foo2() {
        cout << "Foo2's descructor" << endl;
    }
}; 

void showFooByPtr(Foo1 *foo) {
    foo->showR();
    foo->showV();
    foo->showV2();
    foo->showV3();
}

void showFooByRef(Foo1 &foo) {
    foo.showR();
    foo.showV();
    foo.showV2();
    foo.showV3();
}

int main() { 
    Foo1 f1; 
    Foo2 f2; 

    // dynamic 
    showFooByPtr(&f1); 
    cout << endl;
    showFooByPtr(&f2);
    cout << endl;
 
    // dynamic 
    showFooByRef(f1); 
    showFooByRef(f2);
    cout << endl; 

    // static
    f1.showR(); 
    f1.showV(); 
    f1.showV2(); 
    f1.showV3(); 
    f2.showR(); 
    f2.showV(); 
    f2.showV2(); 
    f2.showV3(); 

    cout << endl; 
    return 0;
}
