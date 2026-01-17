#include <iostream>
using namespace std;

/*
    객체지향 프로그래밍 이해
    -> 현실에 존재하는 사물과 대상, 그리고 그에 따른 행동을 있는 그대로
    실체화 시키는 형태의 프로그래밍

    객체: 하나 이상의 상태 정보(데이터)와 하나 이상의 행동(기능)으로 구성
*/
class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }

    int SalesApple(int money)
    {
        int num = money / APPLE_PRICE;
        myMoney += money;
        numOfApples -= num;
        return num; // 사가는 사과수 반환
    }

    void ShowResults()
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "남은 돈: " << myMoney << endl << endl;
    }

};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller& seller, int money)
    {
        numOfApples += seller.SalesApple(money); // 메세지 전달 기법 사용
        myMoney -= money;
    }
    void ShowBuyResult()
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};

int main()
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);

    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000); // 과일 구매!

    cout << "과일 판매자의 현황" << endl;
    seller.ShowResults();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();
    return 0;
}