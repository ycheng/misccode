#include <iostream>

using namespace std; 

class Cls1
{
  public:
    Cls1();
    void word();
    // virtual void word();
};

Cls1::Cls1()
{}

void Cls1::word()
{
  cout<<"this function is in Cls1!\n";
}

class Cls2:public Cls1
{
   public:
      Cls2();
      void word2();
};

Cls2::Cls2()
{}

void Cls2::word2()
{
   Cls2::word();
   cout<<"Reuse in Cls2!!\n";
}

int main()
{
   Cls2 test;
   test.word2();

return 0;
}