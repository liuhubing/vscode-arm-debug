
/*Model:
Uint id1;

View-Model:
func value;

id1.bindset();
id2.bindset();

View*/
#include <iostream>

using namespace std;

class Uint
{
    public:
        int value;
        int index;
        int (*p1)(int a) = nullptr;

        //function ;
    void setFunc(int (*p)(int a), int i)
    {
        index = i;
        p1 = p;
    }

    // 重载赋值运算符（ = Uint）
    Uint &operator= (const Uint &u)  
    {
        this->value =  u.value;
        return *this;
    }
    
    // 重载赋值运算符（ = int）
    Uint &operator= (int i)  
    {
        this->value =  i;
        if(p1 != nullptr)
            p1(index);
        return *this;
    }
};

// index in vm
int func(int a)
{
    cout << "public func index : " << a << endl;

    return 0;
}

int main()
{
    Uint i; // Define in module

    i.setFunc(func, 10); // func set in vm

    i = 3; // Used in module
    return 0;
}
