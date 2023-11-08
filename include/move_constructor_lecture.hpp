#include <iostream>

class Integer{
private:
    int* m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer& obj);
    Integer(Integer&& obj) noexcept;
    ~Integer();
    int GetValue() const;
    void SetValue(int value);

};