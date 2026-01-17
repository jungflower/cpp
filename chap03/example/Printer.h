#ifndef __PRINTER_H__
#define __PRINTER_H__

class Printer
{
private:
    char str[100];

public:
    void SetString(const char* setstr);
    void ShowString();
};

#endif