#include <iostream>

// 함수 오버로딩
void Myfunc(void)
{
    std::cout << "MyFunc(void) called" << std::endl;
}

void Myfunc(char c)
{
    std::cout << "MyFunc(char c) called" << std::endl;
}

void Myfunc(int a, int b)
{
    std::cout << "MyFunc(int a, int b) called" << std::endl;
}

int main(){

    Myfunc();
    Myfunc('A');
    Myfunc(12, 13);

    return 0;
}