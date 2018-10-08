
#include <string>

class Point2D
{
private:
    int m_x, m_y;
public:
    Point2D(int x, int y): m_x(x), m_y(y) {}
    int value() {return m_x + m_y; } // only for demo
};

class Creature
{
private:
    std::string m_name;
    Point2D m_loc;
public:
    Creature(std::string name, Point2D loc): m_name(name), m_loc(loc) {}
};