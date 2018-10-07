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
    cout << "Foo1 obj" << endl;
    showFooByPtr(&f1); 
    cout << endl;
    cout << "Foo2 obj, use Foo1 Ptr" << endl;
    showFooByPtr(&f2);
    cout << endl;
 
    // dynamic 
    cout << "Foo1 obj" << endl;
    showFooByRef(f1); 
    cout << "Foo2 obj, use Foo2 Ref" << endl;
    showFooByRef(f2);
    cout << endl; 

    // static
    cout << "Foo1 obj" << endl;
    f1.showR(); 
    f1.showV(); 
    f1.showV2(); 
    f1.showV3(); 
    cout << "Foo2 obj" << endl;
    f2.showR(); 
    f2.showV(); 
    f2.showV2(); 
    f2.showV3(); 

    cout << endl; 
    cout << "before return 0 from main, no more output after here from main." << endl;
    return 0;
}
