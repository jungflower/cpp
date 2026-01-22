#include <iostream>
using namespace std;

class Temporary
{
private:
    int num;
public:
    Temporary(int n) : num(n)
    {
        cout << "create obj: " << num << endl;
    }
    ~Temporary()
    {
        cout << "destroy obj: " << num << endl;
    }
    void ShowtempInfo()
    {
        cout << "My num: " << num << endl;
    }
};

// 임시 객체 생성 
int main()
{
    Temporary(100);
    cout << "******** after make! " << endl << endl;

    Temporary(200).ShowtempInfo();
    cout << "******** after make! " << endl << endl;

    const Temporary &ref = Temporary(300);
    cout << "******** end of main!" << endl << endl;
    return 0;
}