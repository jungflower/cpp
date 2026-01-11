#include <iostream>

// inline 함수
/*
    매크로를 이용한 함수의 인라인화는 전처리기에 의해 처리되지만,
    키워드 inline을 이용한 함수의 인라인화는 컴파일러에 의해 처리
*/
inline int SQUARE(int x)
{
    return x*x;
}

int main(void)
{
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(12) << std::endl;
    return 0;
}