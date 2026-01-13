#include <iostream>
using namespace std;

void Addnum(int &ref){
    ref++;
}

void InverseSign(int &num){
    num *= -1;
}

int main6()
{
    
    /*
    int num = 10;
    Addnum(num);
    cout << "add + 1 : " << num << endl;
    InverseSign(num);
    cout << num << endl;
*/
    const int num = 12;
    const int* ptr = &num;
    const int *(&ref) = ptr;

    cout << "ptr: " << *ptr << endl;
    cout << "ref: " << *ref << endl;
    return 0;
}