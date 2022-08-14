#include "menu.h"
#include "kornyezet.h"
int main()
{
    #if defined(WIN32) || defined(_WIN32)
    SetConsoleCP(1250); SetConsoleOutputCP(1250);
    #endif
    menu();
    return 0;
}
