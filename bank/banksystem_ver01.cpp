/*
    banking management system ver 0.1
    author=junghwalee
*/
#include <iostream>
#include <cstring>
using namespace std;

#define name_LEN 30

void ShowMenu(); // 메뉴 출력
void MakeAccount(); // 1. 계좌 개설
void DepositMoney(); // 2. 입금
void WithdrawMoney(); // 3. 출금
void ShowAllAccInfo(); // 4. 잔액 조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INFO, EXIT};

typedef struct 
{
    int ID;
    int balance;
    char name[name_LEN]; // 고객 이름
} Account;

Account acc[100]; // account 저장 위한 배열
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
    char cus_name[name_LEN];

    cout << "[1. 계좌 개설]" << endl;
    cout << "1) 계좌 ID: ";  cin >> id;
    cout << "2) 이름: "; cin >> cus_name;
    cout << "3) 입금액: "; cin >> balance;

    acc[accNum].ID = id;
    acc[accNum].balance = balance;
    strcpy(acc[accNum].name, cus_name);
    ++accNum;
    return;
}

void DepositMoney()
{
    int money, id;
    cout << "[2. 입금]" << endl;
    cout << "1) 입금할 계좌ID: "; cin >> id;
    cout << "2) 입금할 금액: "; cin >> money;
    for(int i = 0; i < accNum; ++i){
        if(id == acc[i].ID){
            acc[i].balance += money;
            cout << "잔액: " << acc[i].balance << endl;
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
        if(id == acc[i].ID){
            if(acc[i].balance < money){
                cout << "잔액 부족 !!!! " << endl;
                return;
            }
            acc[i].balance -= money;
            cout << "잔액: " << acc[i].balance << endl;
            cout << "출금 완료" << endl;
            return;
        }
    }
    cout << "ID가 존재하지 않습니다." << endl;
    
}
void ShowAllAccInfo()
{
    for(int i = 0; i < accNum; ++i){
        cout << "계좌 ID: " << acc[i].ID << endl;
        cout << "이름: " << acc[i].name << endl;
        cout << "금엑: " << acc[i].balance << endl;
    }
}


