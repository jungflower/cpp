#include <iostream>
using namespace std;

/*
    <Call by reference>
    주소 값을 전달받아서, 함수 외부에 선언된 변수에 접근하는 형태의 함수호출
*/

void SwapbyRef(int *ptr1, int *ptr2)
{
    int tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

// 포인터로 주소값 전달하듯이 사용 가능
void SwapbyRef2(int &ref1, int &ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main3()
{
    int val1 = 10;
    int val2 = 20;
    SwapbyRef(&val1, &val2);
    //SwapbyRef2(val1, val2);
    cout << "val1: " << val1 << endl; // 20
    cout << "val2: " << val2 << endl; // 10
    return 0;
}