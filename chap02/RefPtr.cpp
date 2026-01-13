#include <iostream>
using namespace std;

int main2()
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;
    cout << *pref << endl;
    num = 13;
    cout << **dpref << endl;
    return 0;
}