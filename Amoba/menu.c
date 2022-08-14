#include "menu.h"
#include "debugmalloc.h"
#include "econio.h"
#include <stdbool.h>
#include <stdio.h>
#include "adatbe.h"
#include "filekezeles.h"
#include "utmutato.h"

//menu függvény felel a program folytonosságáért, egyetlen helyes kimenetként funkcionál
//a felhasználó ki tudja választani, hogy hogyan szeretné folytatni a programot

void menu()
{
        int vegso = 0;
        int iq =101;
        char valasz[2];
        bool jo_valasz = false;

        do
        {
            do
            {
                iq--;
                econio_clrscr();
                printf("XOXOXOXOXO - AMOBA - OXOXOXOXOX\n\n");
                if(iq<100)
                {
                    econio_textcolor(COL_RED);
                    printf("Hasznalja a szamjegyeket!\n(1,2,3,4)\n");
                    econio_textcolor(COL_WHITE);
                }
                printf("Lehetosegek:\n");
                printf("1 Jatek\n");
                printf("2 Mentett jatek\n");
                printf("3 Utmutato\n");
                printf("4 Kilepes\n");
                printf("Valaszom:");

                scanf("%s",&valasz);

                vegso=valasz[0]-'0';                            //a karakterként beolvasot "folytatási lehetpséget" számá konvertáljuk
                if(vegso<5 && vegso>0 && valasz[1] =='\0')      //ellenőrizük, hogy létezik-e a lehetőség
                {
                    jo_valasz = true;
                }
            }while(!jo_valasz);
            switch(vegso)                                       //eljutattjuk a felhasználót kiválaszt lehetőségért felelős függvényhez
            {
            case 1:
                adatbe();
                break;
            case 2:
              beol();
                break;
            case 3:
                utmutato();
                break;
            case 4:
                econio_clrscr();
                break;
            }
            iq++;
        }while(vegso != 4);                                     //abban az esetben ér véget teljesen a program ha felhasználó a "kilepes" - t választja a menüben, más esetben nem érhet véget a program
}
