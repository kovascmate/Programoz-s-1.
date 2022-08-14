#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "logika.h"
#include "megjelenites.h"
#include "debugmalloc.h"
#include "memory_management.h"
#include "kornyezet.h"

// a "konnyu" függvény egy random generátor segítségével lépi a számítógép lépését
// a függvény a tábla méretét és a pálya elsõ elemének pointerét kapja meg
void konnyu(int meret,int **palya,int *lepet)
{
        srand(time(NULL));
            int szaml = 0;
    for(int i = 0; i <meret;i++)     //megszámlálja, hogy hány darab üres hely található a táblán
    {
        for(int j = 0; j <meret;j++)
            {
                if(palya[i][j]==0)
                    szaml++;
            }
    }
    int rak = rand()%szaml;                         //egy random szám segítségével kiválasztja az egyik üres helyet
    szaml = 0;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // végigmegyünk a tömbön és amikor elérünk a random generált számhoz akkor megteszük a lépésünket
    for(int i = 0; i <meret && szaml <=rak;i++)
    {
        for(int j = 0; j <meret && szaml <=rak;j++)
            {
                if(palya[i][j] == 0)
                    {
                      if(szaml == rak)
                        {
                          palya[i][j] = 2;
                          lepet[0] = i;
                          lepet[1] = j;
                        }
                    szaml++;
                    }
            }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// a "kozep" függvény egy vele egyezõ karakter mellé teszi meg a következõ lépést
// a függvény a tábla méretét és a pálya elsõ elemének pointerét kapja meg
void kozep(int meret,int **palya,int *lepet)
{
    int ki = 0;

    for(int i = 0; i <meret && ki ==0;i++)
    {
        for(int j = 0; j <meret && ki == 0;j++)         //végig megyünk a tombon elemezunk minden elemet
            {
                if(palya[i][j] == 2)
                {
                    ////////////////////////////////////////
                    //          vizszintes
                    if(palya[i][j+1] == 0 && j < meret-1)
                    {
                        palya[i][j+1] = 2;
                        ki++;
                        lepet[0] = i;
                        lepet[1] = j+1;
                    }
                    else if(palya[i][j-1] == 0 && j > 0)
                    {
                        palya[i][j-1] = 2;
                        ki++;
                        lepet[0] = i;
                        lepet[1] = j-1;
                    }
                    ////////////////////////////////////////
                    //          fuggoleges
                    else if(palya[i+1][j] == 0 && i<meret-1)
                    {
                        palya[i+1][j] = 2;
                        ki++;
                        lepet[0] =i+1;
                        lepet[1] =j;
                    }
                    else if(palya[i-1][j] == 0 && i>0)
                    {
                        palya[i-1][j] = 2;
                        ki++;
                        lepet[0] =i-1;
                        lepet[1] =j;
                    }
                    ////////////////////////////////////////
                    //          atlos
                    else if(palya[i+1][j+1] == 0 && i<meret-1 && j<meret-1)
                    {
                      palya[i+1][j+1] = 2;
                      ki++;
                        lepet[0] =i+1;
                        lepet[1] =j+1;
                    }
                    else if(palya[i-1][j+1] == 0 && i>0 && j<meret-1)
                    {
                      palya[i-1][j+1] = 2;
                      ki++;
                        lepet[0] = i-1;
                        lepet[1] =j+1;

                    }
                    else if(palya[i-1][j-1] == 0 && i>0 && j>0)
                    {
                      palya[i-1][j-1] = 2;
                      ki++;
                        lepet[0] =i-1;
                        lepet[1] =j-1;
                    }
                    else if(palya[i+1][j-1] == 0 && i<meret-1 && j>0)
                    {
                      palya[i+1][j-1] = 2;
                      ki++;
                        lepet[0] = i+1;
                        lepet[1] = j-1;
                    }
                    ////////////////////////////////////////
                }
            }
    }
    if(ki==0)                    //amenyiben nem sikerült lépni meghívjuk a "konnyu" függvényt és random lépünk
    {
        konnyu(meret,palya,lepet);
    }
}

void nehez(int meret, int **palya,int *lepet)
{
    //////////////////////////////////////////////////////////////////////////////
    //      dinamikus "ellenözö" mátrix létrehozása, majd kinullázása
    int **nes = foglal(meret);
    //////////////////////////////////////////////////////////////////////////////
    for(int i =0; i <meret; i++)
    {
        for(int j = 0; j <meret;j++)
        {
            for(int y = 0; y < 25;y++)
            {
                int oszlop_differencia = range[y][1];
                int sor_differencia = range[y][0];
                int ellenorzo_ertek = range[y][2];
                int fix = palya[i][j];
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if(fix == 1)            //ellenfél lépéseinek ellenõrzése
                {
                   if(i+oszlop_differencia > 0 && i+oszlop_differencia<meret && j+sor_differencia > 0 && j+sor_differencia <meret)
                   {
                        if(palya[i+oszlop_differencia][j+sor_differencia] == 0)
                        {
                            nes[i+oszlop_differencia][j+sor_differencia] += 5-ellenorzo_ertek;
                        }
                        else if(palya[i+oszlop_differencia][j+sor_differencia] == fix)
                        {
                            if(i+(oszlop_differencia)*2>=0 && i+(oszlop_differencia)*2<meret && j+(sor_differencia)*2>=0 && j+(sor_differencia)*2<meret)
                            {
                                if(ellenorzo_ertek == 1 && palya[i+(oszlop_differencia)*2][j+(sor_differencia)*2] == 0)
                                {
                                    nes[i+(oszlop_differencia)*2][j+(sor_differencia)*2] +=100;
                                    if(i+(oszlop_differencia)*4>=0 && i+(oszlop_differencia)*4<meret && j+(sor_differencia)*4>=0 && j+(sor_differencia)*4<meret)
                                    {
                                        if(ellenorzo_ertek == 1 && palya[i+(oszlop_differencia)*3][j+(sor_differencia)*3] == fix)
                                        {
                                            nes[i+(oszlop_differencia)*2][j+(sor_differencia)*2] +=350;
                                        }
                                    }
                                }
                                else if(i+(oszlop_differencia)*3>=0 && i+(oszlop_differencia)*3<meret && j+(sor_differencia)*3>=0 && j+(sor_differencia)*3<meret && palya[i+(oszlop_differencia)*2][j+(sor_differencia)*2] == 1)
                                {
                                    if(ellenorzo_ertek == 1 && palya[i+(oszlop_differencia)*3][j+(sor_differencia)*3] == 0)
                                        {
                                            nes[i+(oszlop_differencia)*3][j+(sor_differencia)*3] +=250;
                                        }
                                }
                            }
                        }
                    }
                }
                else if(fix == 2)            //program lépéseinek ellenõrzése
                {
                   if(i+oszlop_differencia > 0 && i+oszlop_differencia<meret && j+sor_differencia > 0 && j+sor_differencia <meret)
                   {
                        if(palya[i+oszlop_differencia][j+sor_differencia] == 0)
                        {
                            nes[i+oszlop_differencia][j+sor_differencia] += 6-ellenorzo_ertek;
                        }
                        else if(palya[i+oszlop_differencia][j+sor_differencia] == fix)
                        {
                            if(i+(oszlop_differencia)*2>=0 && i+(oszlop_differencia)*2<meret && j+(sor_differencia)*2>=0 && j+(sor_differencia)*2<meret)
                            {
                                if(ellenorzo_ertek == 1 && palya[i+(oszlop_differencia)*2][j+(sor_differencia)*2] == 0)
                                {
                                    nes[i+(oszlop_differencia)*2][j+(sor_differencia)*2] +=110;
                                    if(i+(oszlop_differencia)*4>=0 && i+(oszlop_differencia)*4<meret && j+(sor_differencia)*4>=0 && j+(sor_differencia)*4<meret)
                                    {
                                        if(ellenorzo_ertek == 1 && palya[i+(oszlop_differencia)*3][j+(sor_differencia)*3] == fix)
                                        {
                                            nes[i+(oszlop_differencia)*2][j+(sor_differencia)*2] +=450;
                                        }
                                    }
                                }
                                else if(i+(oszlop_differencia)*3>=0 && i+(oszlop_differencia)*3<meret && j+(sor_differencia)*3>=0 && j+(sor_differencia)*3<meret && palya[i+(oszlop_differencia)*2][j+(sor_differencia)*2] == 2)
                                {
                                    if(ellenorzo_ertek == 1 && palya[i+(oszlop_differencia)*3][j+(sor_differencia)*3] == 0)
                                        {
                                            nes[i+(oszlop_differencia)*3][j+(sor_differencia)*3] +=300;
                                        }
                                }
                            }
                        }
                    }
                }
                else if(fix == 1 || fix == 2)
                    nes[i][j] = 0;
            }
        }
    }
    int max[2]= {0,0};
    for(int i = 0; i < meret;i++)
        {
            for(int j = 0; j <meret;j++)
            {
              if(nes[i][j] > nes[max[0]][max[1]] && palya[i][j] == 0)
              {
                  max[0] = i;
                  max[1] = j;
              }
            }
        }
        palya[max[0]][max[1]] = 2;          //lepes megtetele
        lepet[0] = max[0];
        lepet[1] = max[1];

    felszab(nes,meret);                     //"tükör" tömb felszabaditása
}
