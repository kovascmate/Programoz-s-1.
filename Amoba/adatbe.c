#include <stdio.h>
#include <stdbool.h>
#include "adatbe.h"
#include "megjelenites.h"
#include "memory_management.h"
#include "debugmalloc.h"
#include "econio.h"

//az "adatbe" függvény felelős a felhasználó adatainak bekéréséért és ezeket eljutatja a játék működését levezénylő függvényekhez

void adatbe()
{
    int **palya;
    char nev[20];
    char valasz[3];
    int meret = 0;
    int lvl;
    bool elso = true;
    bool uj_jatek = false;

    do
    {
        //felhasznalo nev bekerjük
        econio_clrscr();
        printf("Adja meg az adatait!");
        econio_gotoxy(2,1);
        printf("Nev:");
        scanf("%s",&nev);
        econio_clrscr();

        //bekerjük a felhasználótól, hogy mekkora pályán szeretne játszani
        do
        {
            if(elso == false)
            {
                econio_textcolor(COL_RED);
                printf("Tul kicsi vagy nagy palya meretet adott meg, probalja ujra.\n");
                econio_textcolor(COL_WHITE);
            }
            printf("Adja meg az adatait!\n");
            printf("Palya meret:");                 //pálya bekérése
            scanf("%s",&valasz);
            if(valasz[1] == '\0')
            {
                meret=valasz[0]-'0';
            }
            else if(valasz[2] == '\0')
            {
                meret=(valasz[0]-'0')*10;
                meret = meret+(valasz[1]-'0');
            }
            elso = false;
            econio_clrscr();
        }while(!(meret>3 && meret<27));
        econio_clrscr();
        elso = true;

        //felhasználótol bekérjük, hogy milyen ügyeségű ellenfél ellen szeretne játsznai
        do
        {
            if(elso == false)
            {
                econio_textcolor(COL_RED);
                printf("Nem sikerult kivalasztania az ugyessegi csoportot.\n");
                econio_textcolor(COL_WHITE);
            }
            econio_gotoxy(0,1);
            printf("Adja meg az adatait!");
            econio_gotoxy(2,2);
            printf("Nehezseg:");
            econio_gotoxy(2,3);
            printf("1 konnyu");
            econio_gotoxy(2,4);
            printf("2 normal");
            econio_gotoxy(2,5);
            printf("3 nehez");
            econio_gotoxy(12,2);
            scanf("%s",&valasz);
            if(valasz[0]-'0' <4 && valasz[0]-'0'>0 && valasz[1]=='\0')
            {
                lvl = valasz[0]-'0';
            }
            econio_clrscr();
            elso = false;
        }while((lvl != 1 && lvl != 2 && lvl != 3));
        elso = true;
        palya =  foglal(meret);                                 //lefoglaltatjuk a játékhoz szükséges pályának a memoriaterületet
        uj_jatek = csomopont(palya,meret,nev,lvl);              //elinditatjuk a jatekot, visszatérési értéke a jatekot levezénylő függvénynek határozza meg, hogy kilépünk-e a főggvényből vagy új játék kezdődik-e
    }while(uj_jatek== true);
}
