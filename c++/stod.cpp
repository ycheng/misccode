// stod example, g++ -std=c++11 stod.cpp -o stod
#include <iostream>   // std::cout
#include <string>     // std::string, std::stod


extern "C"
{
#include "cstod.h"
}


int main ()
{

  std::string orbits ("365.24 29.53");
  std::string::size_type sz;     // alias of size_t

  double earth;
  earth = std::stod (orbits, &sz);
  earth = cstod(orbits.c_str());
  double moon = std::stod (orbits.substr(sz));
  std::cout << "The moon completes " << (earth/moon) << " orbits per Earth year.\n";
  return 0;
}
