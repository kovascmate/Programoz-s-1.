#include <stdio.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "adatbe.h"
#include "ellenorzes.h"
#include "kornyezet.h"
#include "memory_management.h"
#include "logika.h"
#include "csomopont.h"
#include "filekezeles.h"
#include "megjelenites.h"
#include "econio.h"
#include "uj_jatek_szandek.h"

bool csomopont(int **palya, int meret,char *nev,int level)
{
    palya[meret/2][meret/2] = 2;                //az elso fix lepes
    bool uj_jatek = false;
    bool kilep = false;
    bool vege = false;
    bool jo_hely = false;

    int lepet[2] = {0};
    int rossz_lepes = 0;
    int hatralevo_lepesek = meret*meret-1;

    megjelenites(nev,meret,level,palya,semmi);      //a konzolos felületen megjelenitetjük a pályát a játékállásnak megfelelően

    do
    {
        //a felhasználótól bekérjük, hogy mit szeretne csinálni, kilepni vagy elhelyezni egy lepest
        jo_hely = false;
        char lepes[6];
        printf("\nKovetkezo lepes:");
        scanf("%s",&lepes);
        for(int i = 0; i <6;i++)
        lepes[i] = tolower(lepes[i]);

        while(jo_hely==false && vege==false && kilep==false)
        {
            if(rossz_lepes > 0)
                    {
                    megjelenites(nev,meret,level,palya,0);
                    econio_gotoxy(0,meret+7);
                    econio_textcolor(COL_RED);
                    printf("Eddigi rossz lepesek:%d",rossz_lepes);
                    econio_textcolor(COL_WHITE);
                    econio_gotoxy(0,meret+8);
                    printf("Kovetkezo lepes:");
                    scanf("%s",&lepes);
                    }
            if(!(strcmp("kilep",lepes)&&strcmp("kilép",lepes)))
                {
                    //kilepes esetén fájlba elmentjük a játékállást
                    kiir(nev,meret,level,palya);
                    econio_clrscr();
                    printf("A jatek elmentesre kerult.\nVarom vissza!\n");
                    kilep = true;
                }
            else if(lepes[0]>='a' && lepes[0]<='z')
                {
                    //amenyiben a felhasználó lépésnek tűnő kombinációt adott meg a bemeneten, ellenőrizük, hogy érvényesnek számít-e az adott pálya terület
                    //ha nem érvényes kombinációt adott meg akkor számláljuk és az adott korlát elérésekor végetvetünk a játéknak
                    jo_hely = false;
                    for(int i = 0; i <6;i++)
                    {
                        lepes[i] = tolower(lepes[i]);
                    }
                    if(lepes[0]-'a'<meret && lepes[0]-'a'>=0)                  //vizsgáljuk hogy az elsõ karakter betû-e
                    {
                        lepet[0] = lepes[0]-'a';                                //ha igen akkor a kordinátját eltaroljuk
                        if(lepes[2] == '\0')                                    //vizsgáljuk, hogy egy vagy kétjegyû számot kaptunk-e
                        {
                            lepet[1] = lepes[1]-'0'-1;                          //ha egy akkor eltároljuk
                        }
                        else if(lepes[3] == '\0')                               //ha nem egyjegyû akkor ismét vizsgáljuk
                        {
                            lepet[1] = (lepes[1]-'0')*10+lepes[2]-'0'-1;        //ha helyes és kétjegyû akkor eltároljuk
                        }
                        else
                            {
                               jo_hely = false;
                            }
                        if(lepet[1]>=meret)
                        {
                            jo_hely=false;
                        }
                        else if(palya[lepet[0]][lepet[1]] == 0)
                        {
                            palya[lepet[0]][lepet[1]] = 1;                      //amennyiben "szabad" az adott terület megteszük a lépést
                            jo_hely = true;
                        }
                        else if(palya[lepet[0]][lepet[1]] != 0)
                        {
                            jo_hely = false;
                        }
                    }
                }
                else
                {
                    jo_hely = false;
                }
                if(jo_hely == false)
                {
                     rossz_lepes++;
                }
                else if(jo_hely)
                {
                    rossz_lepes=0;
                }
                if(rossz_lepes==3)
                {
                        vege=true;
                }
        }
        if(vege && rossz_lepes == 3)
        {
            econio_clrscr();
            megjelenites(nev,meret,level,palya,hibas_lepesek);
            uj_jatek = uj_jatek_szandek(meret);
            felszab(palya,meret);
        }
        else if(vege)
        {
            econio_clrscr();
            megjelenites(nev,meret,level,palya,megtelt);
            uj_jatek = uj_jatek_szandek(meret);
            felszab(palya,meret);
        }

        if(kilep == false && vege == false)
        {

            hatralevo_lepesek--;
             if(ellenorzes(meret,palya,lepet[0],lepet[1]) == true)       //"elküldjük" ellenõrzésre a pályát, hogy fenn áll-e a nyerés
                {

                    econio_clrscr();
                    megjelenites(nev,meret,level,palya,felhasznalo_nyert);
                    uj_jatek = uj_jatek_szandek(meret);
                    felszab(palya,meret);
                    vege = true;
                }
            else if(hatralevo_lepesek == 0)
                {
                    vege = true;
                    megjelenites(nev,meret,level,palya,megtelt);
                    felszab(palya,meret);
                }
            else if(vege == false)
            {
                megjelenites(nev,meret,level,palya,semmi);
                switch(level)                                       //a kiválasztott nehézségi szinthez tartozó gondolkodó egységet meghívja
                {
                    case 1:
                        konnyu(meret,palya,lepet);
                    break;
                    case 2:
                        kozep(meret,palya,lepet);
                    break;
                    case 3:
                        nehez(meret,palya,lepet);
                    break;
                }
                hatralevo_lepesek--;
                if((ellenorzes(meret,palya,lepet[0],lepet[1])) == true )//"elküldjük" ellenõrzésre a pályát, hogy fenn áll-e a nyerés
                    {
                        econio_clrscr();
                        megjelenites(nev,meret,level,palya,program_nyert);
                        uj_jatek = uj_jatek_szandek(meret);
                        felszab(palya,meret);
                        vege = true;
                    }
                else if(hatralevo_lepesek == 0)
                    {
                        vege = true;
                        megjelenites(nev, meret,level,palya,megtelt);
                        felszab(palya,meret);
                    }
                else
                    {
                        megjelenites(nev,meret,level,palya,semmi);
                    }
            }
        }
        if(kilep)
        {
            uj_jatek = false;
        }
    }while(kilep==false && vege==false);
    econio_clrscr();
    if(uj_jatek == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
