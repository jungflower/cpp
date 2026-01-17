#if 0
#include <iostream>
using namespace std;

/*
    클래스 접근 제어 지시자
    public: 어디서든 접근 허용
    protected: 상속관계에 놓여잇을 때, 유도 클래스에서의 접근 허용
    private: 클래스 내에서만 접근 허용

    구조체 -> 기본 public
    클래스 -> 기본 private
*/
namespace CAR_CONST
{
    enum
    {
        ID_LEN    = 20,
        MAX_SPD   = 200,
        FUEL_STEP = 2,
        ACC_STEP  = 1,
        BRK_STEP  = 10
    };
}

// 클래스로 표현
class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN]; // 소유자 ID
    int fuelGauge; // 연료량
    int curSpeed; // 현재 속도

public:
    void InitMembers(const char* ID, int fuel);
    void ShowCarState(); // 상태정보 출력
    void Accel(); // 엑셀, 속도증가
    void Break(); // 브레이크, 속도감소

};

void Car::InitMembers(const char* ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState(){
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << endl;
    cout << "현재 속도: " << curSpeed << endl;
}
void Car::Accel(){
    if(fuelGauge <= 0)  return;
    else    fuelGauge -= CAR_CONST::FUEL_STEP;

    if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD){
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break(){
    if(curSpeed < CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main()
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    return 0;
}
#endif