#include <iostream>
using namespace std;

class FruitSeller
{
private:
    const int APPLE_PRICE; // const 상수에서는 이니셜라이저 사용 필수
    int numOfApples;
    int myMoney;

public:
    FruitSeller(int price, int num, int money)
        :APPLE_PRICE(price), numOfApples(num), myMoney(money)
    {
    }

    int SalesApple(int money)
    {
        if(money < 0){
            cout << "잘못된 정보가 전달되어 판매를 취소합니다." << endl;
            return 0;
        }
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
    FruitBuyer(int money)
        : myMoney(money), numOfApples(0)
    {
    }

    void BuyApples(FruitSeller& seller, int money)
    {
        if(money < 0){
            cout << "잘못된 정보가 전달되어 판매를 취소합니다." << endl;
            return;
        }
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
    FruitSeller seller(1000, 20, 0);

    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000); // 과일 구매!

    cout << "과일 판매자의 현황" << endl;
    seller.ShowResults();
    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();
    return 0;
}