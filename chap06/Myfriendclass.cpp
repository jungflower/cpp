#include <iostream>
using namespace std;

class Girl;
class Boy
{
private:
    int height;
    friend class Girl; // Girl class에 의한 friend 선언
public:
    Boy(int len) : height(len){}
    void ShowYourFriendinfo(Girl &frn);
};

class Girl
{
private:
    char phNum[20];
public:
    Girl(const char* num){
        strcpy(phNum, num);
    }
    void ShowYourFriendinfo(Boy& frn);
    friend class Boy; // boy클래스에 대한 friend 선언
};

void Boy::ShowYourFriendinfo(Girl& frn)
{
    cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendinfo(Boy& frn)
{
    cout << "his height: " << frn.height << endl;
}
int main()
{
    Boy boy(170);
    Girl girl("010-2123-5667");
    boy.ShowYourFriendinfo(girl);
    girl.ShowYourFriendinfo(boy);
    return 0;
}