#include <stdio.h>
#include "econio.h"
#include "megjelenites.h"
#include "csomopont.h"

void megjelenites(char *nev,int meret,int level, int **palya,int veg)
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                  "fejléc"
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //                   itt függvény megjeleníti az "adatbe"-bõl származó adatokat
    {
    econio_clrscr();
    econio_gotoxy(1,1);
    printf("Nev: %s\tPalya meret: %dx%d\tNehezseg: ",nev,meret,meret);
    switch (level)
    {
        case 1:
            printf("konnyu\t");
        break;
        case 2:
            printf("normal\t");
        break;
        case 3:
            printf("nehez\t");
        break;
    }
    printf(" Jeled:\t");
    econio_textcolor(COL_RED);
    printf("X");
    econio_textcolor(COL_WHITE);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //          "kozep resz"
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    {
    //palya kirajzolo ciklus
    //          |
    //          |
    //          |
    //          V
    econio_gotoxy(4,3);                         //ures resz a keret elott
    for(int i = 0; i <meret;i++)                //felso keret letrehozzasa
    {
        printf("%c ",'A'+i);                    //felsõ betusor
    }

    printf("\n  + ");                       //keret szele

    for(int i = 0; i <meret;i++)
    {
        printf("- ");                   //felso keret
    }
    printf("+\n");                          //keret szele

    for(int i = 0; i < meret;i++)
    {
        if(i+1>9)
            {
            printf("%d| ",i+1);               //bal szamozas es keret
        }
        else{
            printf("%d | ",i+1);
        }

        for(int j = 0; j <meret;j++)
        {
            if((i+j)%2 == 0)
            {
                econio_textbackground(COL_GREEN);
            }
            if((i+j)%2 == 1)
            {
                econio_textbackground(COL_YELLOW);
            }
            if(palya[j][i] == 0)
            {
                printf(" ");
            }
            else if(palya[j][i] == 1)
            {
                econio_textcolor(COL_RED);
                printf("X");
                econio_textcolor(COL_WHITE);

            }
            else if(palya[j][i] == 2)
            {
                econio_textcolor(COL_BLUE);
                printf("O");
                econio_textcolor(COL_WHITE);
            }
            else if(palya[j][i] == 3)
            {
                econio_textcolor(COL_BLACK);
                econio_textbackground(COL_RED);
                printf("X");
                econio_textcolor(COL_WHITE);
            }
            else if(palya[j][i] == 4)
            {
                econio_textcolor(COL_BLACK);
                econio_textbackground(COL_RED);
                printf("O");
                econio_textcolor(COL_WHITE);
            }
            econio_textbackground(COL_BLACK);
            printf(" ");
        }
        econio_gotoxy((meret*2)+4,i+5);
        printf("|\n");                     //jobb keret
    }
    printf("  + ");                         //keret szele
    for(int i = 0; i < meret;i++)
    {
        printf("- ");                     //also keret
    }
    printf("+\n");
    if(veg == felhasznalo_nyert)
    {
        printf("Gratulalok %s, megnyerte a jatekot!\n",nev);
    }
    else if(veg == program_nyert)
    {
        printf("A program megnyerte a játékot!\n");
    }
    else if(veg == megtelt)
    {
        printf("A palya megtelt, a jatek veget ert.");
    }
    else if(veg == hibas_lepesek)
    {
        printf("Egymas utan haromszor nem tudott elfogadhato lepest tenni. A jatekot elvesztette.");
    }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //  pálya kirajzolásnak vége
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
}
