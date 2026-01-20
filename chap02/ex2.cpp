#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2){
    Point *res = new Point;
    res->xpos = p1.xpos + p2.xpos;
    res->ypos = p1.ypos + p2.ypos;
    return *res;
}

int main(){

    Point *ptr1 = new Point{1, 2};
    Point *ptr2 = new Point{3, 4};
    Point& res = PntAdder(*ptr1, *ptr2); // 참조도 받아서 나중에 메모리 해제 고려
    cout << res.xpos << " " << res.ypos << endl;

    delete ptr1;
    delete ptr2;
    delete &res;

    return 0;
}