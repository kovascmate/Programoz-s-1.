#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "logika.h"
#include "megjelenites.h"
#include "debugmalloc.h"
#include "memory_management.h"
#include "kornyezet.h"

// a "konnyu" f�ggv�ny egy random gener�tor seg�ts�g�vel l�pi a sz�m�t�g�p l�p�s�t
// a f�ggv�ny a t�bla m�ret�t �s a p�lya els� elem�nek pointer�t kapja meg
void konnyu(int meret,int **palya,int *lepet)
{
        srand(time(NULL));
            int szaml = 0;
    for(int i = 0; i <meret;i++)     //megsz�ml�lja, hogy h�ny darab �res hely tal�lhat� a t�bl�n
    {
        for(int j = 0; j <meret;j++)
            {
                if(palya[i][j]==0)
                    szaml++;
            }
    }
    int rak = rand()%szaml;                         //egy random sz�m seg�ts�g�vel kiv�lasztja az egyik �res helyet
    szaml = 0;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // v�gigmegy�nk a t�mb�n �s amikor el�r�nk a random gener�lt sz�mhoz akkor megtesz�k a l�p�s�nket
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
// a "kozep" f�ggv�ny egy vele egyez� karakter mell� teszi meg a k�vetkez� l�p�st
// a f�ggv�ny a t�bla m�ret�t �s a p�lya els� elem�nek pointer�t kapja meg
void kozep(int meret,int **palya,int *lepet)
{
    int ki = 0;

    for(int i = 0; i <meret && ki ==0;i++)
    {
        for(int j = 0; j <meret && ki == 0;j++)         //v�gig megy�nk a tombon elemezunk minden elemet
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
    if(ki==0)                    //amenyiben nem siker�lt l�pni megh�vjuk a "konnyu" f�ggv�nyt �s random l�p�nk
    {
        konnyu(meret,palya,lepet);
    }
}

void nehez(int meret, int **palya,int *lepet)
{
    //////////////////////////////////////////////////////////////////////////////
    //      dinamikus "ellen�z�" m�trix l�trehoz�sa, majd kinull�z�sa
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
                if(fix == 1)            //ellenf�l l�p�seinek ellen�rz�se
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
                else if(fix == 2)            //program l�p�seinek ellen�rz�se
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

    felszab(nes,meret);                     //"t�k�r" t�mb felszabadit�sa
}
