#include "operator_overloading_lecture.hpp"

IntegerOverLoading::IntegerOverLoading()
{
    std::cout << "IntegerOverLoading()\n";
    m_pInt = new int(0);
}

IntegerOverLoading::IntegerOverLoading(int value)
{
    std::cout << "IntegerOverLoading(IntegerOverLoading)" << std::endl;
    m_pInt = new int(value);
}

IntegerOverLoading::IntegerOverLoading(const IntegerOverLoading &obj)
{
    std::cout << "IntegerOverLoading(const IntegerOverLoading &)\n";
    m_pInt = new int(*obj.m_pInt);
}

IntegerOverLoading::IntegerOverLoading(IntegerOverLoading&& obj) noexcept
{
    std::cout << "Integer&& \n";
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

IntegerOverLoading::~IntegerOverLoading()
{
    std::cout << "~Integer\n";
    delete m_pInt;
}

int IntegerOverLoading::GetValue() const
{
    return *m_pInt;
}

IntegerOverLoading IntegerOverLoading::operator+(const IntegerOverLoading& a) const
{
    return IntegerOverLoading(*m_pInt + a.GetValue());
}

IntegerOverLoading IntegerOverLoading::operator-(const IntegerOverLoading& other) const
{
    return IntegerOverLoading(*m_pInt - other.GetValue());
}

IntegerOverLoading IntegerOverLoading::operator*(const IntegerOverLoading &other) const
{
    return IntegerOverLoading();
}

bool IntegerOverLoading::operator==(const IntegerOverLoading &other) const
{
    if(other.GetValue() == *m_pInt)
    {
        return true;
    }
    return false;
}

IntegerOverLoading IntegerOverLoading::operator=(const IntegerOverLoading &other)
{
    delete m_pInt;
    m_pInt = new int(*other.m_pInt);
    return *this;
}

void IntegerOverLoading::SetValue(int value)
{
    *m_pInt = value;
}
