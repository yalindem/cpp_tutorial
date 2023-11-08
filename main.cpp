#include <iostream>
#include <array_lecture.hpp>
#include <move_constructor_lecture.hpp>
#include <operator_overloading_lecture.hpp>

namespace operatorOverlading
{
    void operator_overlading_lecture()
    {
        IntegerOverLoading a(5);
        IntegerOverLoading b(5);
        IntegerOverLoading c = a + b;
        IntegerOverLoading d = a - b;
        std::cout << c.GetValue() << "\n";
        std::cout << d.GetValue() << "\n";
        if (c==d)
        {
            std::cout << "true\n";
        }
        else
        {
            std::cout << "false\n";
        }

    }
}

namespace moveConstructorLecture
{
    Integer createIntegerObj()
    {
        Integer temp(42);
        return temp;
    }

    void move_constructor_lecture()
    {
        Integer a;
        Integer b = a;
        Integer c(createIntegerObj());
    }

};

namespace copyConstuctorLecture
{
    Integer Add(int x, int y)
    {
        return Integer(x+y);
    }

    void copy_constructor_lecture()
    {
        Integer i(5);
        Integer i2(i);
        std::cout << i.GetValue();
    }


};

int main()
{
    //moveConstructorLecture::move_constructor_lecture();
    //operatorOverlading::operator_overlading_lecture();
    copyConstuctorLecture::copy_constructor_lecture();
    return 0;
}