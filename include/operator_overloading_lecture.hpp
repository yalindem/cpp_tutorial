#include <iostream>

class IntegerOverLoading{
private:
    int* m_pInt;
public:
    IntegerOverLoading();
    IntegerOverLoading(int value);
    IntegerOverLoading(const IntegerOverLoading& obj);
    IntegerOverLoading(IntegerOverLoading&& obj) noexcept;
    ~IntegerOverLoading();
    int GetValue() const;
    void SetValue(int value);
    IntegerOverLoading operator+(const IntegerOverLoading& other) const;
    IntegerOverLoading operator-(const IntegerOverLoading& other) const;
    IntegerOverLoading operator*(const IntegerOverLoading& other) const;
    bool operator== (const IntegerOverLoading& other) const;
    IntegerOverLoading operator=(const IntegerOverLoading& other);

};