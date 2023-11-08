#include "move_constructor_lecture.hpp"

Integer::Integer()
{
    std::cout << "Integer()\n";
    m_pInt = new int(0);
}

Integer::Integer(int value)
{
    std::cout << "Integer(int)" << std::endl;
    m_pInt = new int(value);
}

Integer::Integer(const Integer &obj)
{
    std::cout << "Integer(const Integer &)\n";
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer&& obj) noexcept
{
    std::cout << "Integer&& \n";
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer::~Integer()
{
    std::cout << "~Integer\n";
    delete m_pInt;
}

int Integer::GetValue() const
{
    return *m_pInt;
}


void Integer::SetValue(int value)
{
    *m_pInt = value;
}
