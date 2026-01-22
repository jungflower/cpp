#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char* name;
    int age;

public:
    Person(const char* myname, int myage) : age(myage)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    // 깊은 복사를 위한 (포인터 참조도 가능하도록)
    Person(const Person& copy) : age(copy.age)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }
    void ShowPersonInfo()   const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor !!" << endl;
    }
};

int main()
{
    Person women1("junghwalee", 27);
    Person women2(women1);
    women1.ShowPersonInfo();
    women2.ShowPersonInfo();
    return 0;
}