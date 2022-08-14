#include <stdio.h>
#include <stdlib.h>

void trim(char szoveg, int meret)
{
    int sv = 0;
    while(sv<=meret && szoveg+sv == ' ')
    {
        elso_kar = sv;
        sv++;
    }
    for(int i = 0; sv <= meret; i++)
    {
        szoveg+i = szoveg+i+sv;
    }

    while

}

int main()
{
    char szoveg[100] = {0};
    szoveg = "    szeretem az oszt  ";

    return 0;
}
