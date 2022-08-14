#include <stdio.h>
#include <stdbool.h >
#include "econio.h"
#include "utmutato.h"
#include "menu.h"
void utmutato()
{
    //a "szabalyok" txt fájlból beolvassuk az aktuális játékszabályokat és megjelnitjük a felhasználónak
    char karakter;
    char kovetkezo[6];
    bool vissza = false;

    do{
        FILE *szabalyok = fopen("szabalyok.txt","r");
        econio_clrscr();
        if(szabalyok == NULL)
        {
            perror("Nem sikerult a fajlt megnyitni.");
            vissza = true;
        }
        else
            {
                while(fscanf(szabalyok,"%c",&karakter) != EOF)
                    {
                        if(karakter == 'X')
                        {
                            econio_textcolor(COL_RED);
                        }
                        if(karakter == 'O')
                        {
                            econio_textcolor(COL_BLUE);
                        }
                        printf("%c",karakter);
                        econio_textcolor(COL_WHITE);

                    }
            fclose(szabalyok);
                scanf("%s",&kovetkezo);
                    if(!stricmp(kovetkezo,"vissza") || !stricmp(kovetkezo,"VISSZA"))
                    {
                        vissza = true;
                    }
            }
    }while(vissza == false);

}
