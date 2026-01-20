/*
    banking management system ver 0.2
    author=junghwalee
*/
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

void ShowMenu(); // 메뉴 출력
void MakeAccount(); // 1. 계좌 개설
void DepositMoney(); // 2. 입금
void WithdrawMoney(); // 3. 출금
void ShowAllAccInfo(); // 4. 잔액 조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INFO, EXIT};

class Account
{
private:
    int accID;
    int balance;
    char *cusname;

public:
    Account(int ID, int balance, char* name) : accID(ID), balance(balance)
    {
        cusname = new char[strlen(name) + 1];
        strcpy(cusname, name);
    }

    Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
    {
        cusname = new char[strlen(ref.cusname) + 1];
        strcpy(cusname, ref.cusname);
    }

    int GetAccID()  {return accID;}

    void Deposit(int money)
    {
        balance += money;
    }

    int Withdraw(int money)
    {
        if(money > balance){ // 출금액 부족 시 0원 반환
            return 0;
        }
        balance -= money;
        return money;
    }

    void ShowAccInfo()
    {
        cout << "계좌 ID: " << accID << endl;
        cout << "이름: " << cusname << endl;
        cout << "금엑: " << balance << endl;
    }

    ~Account()
    {
        delete []cusname;
    }
};

Account* accArr[100]; // account 저장 위한 배열
int accNum = 0; // 계좌 개수

int main()
{
    while(1){
        ShowMenu();
        int choice;
        cout << "선택: ";  cin >> choice;
        cout << endl;

        switch(choice)
        {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INFO:
                ShowAllAccInfo();
                break;
            case EXIT:
                for(int i = 0; i < accNum; ++i){
                    delete accArr[i];
                }
                return 0;
                break;
            default:
                cout << "Illegal selection ..." << endl;
        }
    }
    return 0;
}

void ShowMenu()
{
    cout << "---Menu---" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void MakeAccount()
{
    int id, balance;
    char cus_name[NAME_LEN];

    cout << "[1. 계좌 개설]" << endl;
    cout << "1) 계좌 ID: ";  cin >> id;
    cout << "2) 이름: "; cin >> cus_name;
    cout << "3) 입금액: "; cin >> balance;

    accArr[accNum++] = new Account(id, balance, cus_name);
    return;
}

void DepositMoney()
{
    int money, id;
    cout << "[2. 입금]" << endl;
    cout << "1) 입금할 계좌ID: "; cin >> id;
    cout << "2) 입금할 금액: "; cin >> money;
    for(int i = 0; i < accNum; ++i){
        if(id == accArr[i]->GetAccID()){
            accArr[i]->Deposit(money);
            cout << "입금 완료" << endl;
            return;
        }
    }
    cout << "ID가 존재하지 않습니다." << endl;
}
void WithdrawMoney()
{
    int money, id;
    cout << "[3. 출금]" << endl;
    cout << "1) 출금할 계좌ID: "; cin >> id;
    cout << "2) 출금할 금액: "; cin >> money;
    for(int i = 0; i < accNum; ++i){
        if(id == accArr[i]->GetAccID()){
            if(accArr[i]->Withdraw(money) == 0){
                cout << "잔액 부족 !!!! " << endl;
                return;
            }
            cout << "출금 완료" << endl;
            return;
        }
    }
    cout << "ID가 존재하지 않습니다." << endl;
    
}
void ShowAllAccInfo()
{
    for(int i = 0; i < accNum; ++i){
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}


