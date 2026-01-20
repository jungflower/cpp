#include <iostream>
using namespace std;

/*
    this 포인터
    : 객체 자신의 주소값
*/
class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout << "num=" << num << ", ";
        cout << "address=" << this << endl;
    }
    void ShowSimpleData()
    {
        cout << num << endl;
    }
    SoSimple* GetThisPointer()
    {
        return this;
    }

};

int main2()
{
    SoSimple sim1(100);
    SoSimple *ptr1 = sim1.GetThisPointer();
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();
    return 0;
}