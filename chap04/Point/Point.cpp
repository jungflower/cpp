#include <iostream>
#include "Point.h"

using namespace std;

/*
    멤버 변수를 private으로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서
    안전한 형태로 멤버변수의 접근을 유도하는 방식 = 정보 은닉!
*/
Point::Point(const int& xpos, const int& ypos)
{
    x = xpos;
    y = ypos;
}
int Point::GetX() const
{
    return x;
}
int Point::GetY() const
{
    return y;
}
bool Point::SetX(int xpos)
{
    if(xpos < 0 || xpos > 100){
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    x = xpos;
    return true;
}
bool Point::SetY(int ypos)
{
    if(ypos < 0 || ypos > 100){
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    y = ypos;
    return true;
}