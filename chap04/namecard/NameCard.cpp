#include <iostream>
using namespace std;

enum COMP_POS {CLERK, SENIOR, ASSIST, MANAGER};

class NameCard
{
private:
    char* name;
    char* company;
    char* number;
    char* rank;

public:
    NameCard(const char* myname, const char* mycompany, const char* mynumber, int myrank)
    {
        name = new char[strlen(myname) + 1];
        company = new char[strlen(mycompany) + 1];
        number= new char[strlen(mynumber) + 1];
        rank = new char[4];

        strcpy(name, myname);
        strcpy(company, mycompany);
        strcpy(number, mynumber);
        switch(myrank){
            case CLERK:
                strcpy(rank, "사원");
                break;
            
            case SENIOR:
                strcpy(rank, "주임");
                break;
            
            case ASSIST:
                strcpy(rank, "대리");
                break;
            
            case MANAGER:
                strcpy(rank, "과장");
                break;
        }
    }
    void ShowNameCardInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << number << endl;
        cout << "직급: " << rank << endl << endl;
    }

    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []number;
        delete []rank;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manASSIST("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manASSIST.ShowNameCardInfo();
    return 0;
}