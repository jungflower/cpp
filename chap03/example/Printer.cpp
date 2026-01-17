#include "Printer.h"
#include <iostream>

using namespace std;

void Printer::SetString(const char* setstr)
{
    strcpy(str, setstr);
}
void Printer::ShowString()
{
    cout << str << endl;
}