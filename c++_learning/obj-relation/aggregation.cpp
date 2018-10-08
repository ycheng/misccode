#include <string>

class Teacher
{
private:
    std::string m_name;
};

class Department
{
private:
    // This dept holds only one teacher for simplicity, but it could hold many teachers
    Teacher *m_teacher;
};
