#include <stdio.h>
#include <stdbool.h>
#include "ellenorzes.h"
#include "kornyezet.h"

///////////////////////////////////////////////////////////////////
//      úgy mûködik az ellenorzes hogy a függvény megkapja a pálya méretét, kétdimenziós tömb pointerét ami a pályát tartalmazza és két int ként az utosó lépést
//      az utolsó lépés környezetében vizsgáljuk, hogy fenn áll e a gyõzelem
//      a függvény segítségére szolgál a range tömb, mely tartalmazza az összes helyet ahonan kialakulhat gyõzelem range[xy][0] az oszlop a range[xy][1] sor alapján
//      a range[xy][3] pedig hogy merre alakulhat ki gyõzelem tõle
///////////////////////////////////////////////////////////////////
bool ellenorzes(int meret, int **palya,int oszlop, int sor)
{
    bool nyert = true;
    for(int i = 0;i < 25;i++)
    {
        int oszlop_differencia = range[i][0];
        int sor_differencia = range[i][1];

        switch (range[i][3])
        {
            case jobbra_le:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {
                        if(oszlop+oszlop_differencia+j>=meret || oszlop+oszlop_differencia+j<0 || sor+sor_differencia+j>=meret || sor+sor_differencia+j<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia+j][sor+sor_differencia+j]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                        {
                            for(int j = 0;j<4;j++)
                            {
                                palya[oszlop+oszlop_differencia+j][sor+sor_differencia+j] += 2;
                            }
                            return nyert;
                        }
                }
            continue;
            case le:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {
                        if(oszlop+oszlop_differencia <0 || oszlop+oszlop_differencia>=meret || sor+sor_differencia+j>=meret || sor+sor_differencia+j<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia][sor+sor_differencia+j]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                    {
                        for(int j = 0;j<4;j++)
                            {
                                palya[oszlop+oszlop_differencia][sor+sor_differencia+j] += 2;
                            }
                        return nyert;
                    }
                }
                continue;
            case balra_le:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {
                        if(oszlop+oszlop_differencia-j>=meret || oszlop+oszlop_differencia-j<0 || sor+sor_differencia+j>=meret || sor+sor_differencia+j<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia-j][sor+sor_differencia+j]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                        {
                            for(int j = 0;j<4;j++)
                            {
                                palya[oszlop+oszlop_differencia-j][sor+sor_differencia+j] += 2;
                            }
                            return nyert;
                        }
                }
                continue;
            case vizszintesen_jobbra:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {

                        if(sor+sor_differencia <0 || sor+sor_differencia >= meret || oszlop+oszlop_differencia+j>=meret || oszlop+oszlop_differencia+j<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia+j][sor+sor_differencia]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                        {
                            for(int j = 0;j<4;j++)
                            {
                                palya[oszlop+oszlop_differencia+j][sor+sor_differencia] += 2;
                            }
                            return nyert;
                        }
                }
                continue;
            case vizszintesen_balra:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {
                        if(oszlop+oszlop_differencia-j>=meret || oszlop+oszlop_differencia-j<0 || sor>=meret || sor<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia-j][sor+sor_differencia]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                    {
                        for(int j = 0;j<4;j++)
                            {
                              palya[oszlop+oszlop_differencia-j][sor+sor_differencia] += 2;
                            }
                        return nyert;
                    }
                }
                continue;
            case balra_fel:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {
                        if(oszlop+oszlop_differencia-j>=meret || oszlop+oszlop_differencia-j<0 || sor+sor_differencia-j>=meret || sor+sor_differencia-j<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia-j][sor+sor_differencia-j]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                        {
                            for(int j = 0;j<4;j++)
                            {
                              palya[oszlop+oszlop_differencia-j][sor+sor_differencia-j] += 2;
                            }
                            return nyert;
                        }
                }
                continue;
            case fel:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {

                        if(oszlop>=meret || oszlop<0 || sor+sor_differencia-j>=meret || sor+sor_differencia-j<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia][sor+sor_differencia-j]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                    {
                        for(int j = 0;j<4;j++)
                            {
                              palya[oszlop+oszlop_differencia][sor+sor_differencia-j] += 2;
                            }
                        return nyert;
                    }
                }
                continue;
            case jobbra_fel:
                {
                    nyert = true;
                    for(int j = 0; j <4;j++)
                    {
                        if(oszlop+oszlop_differencia+j>=meret || oszlop+oszlop_differencia+j<0 || sor+sor_differencia-j>=meret || sor+sor_differencia-j<0)
                        {
                            nyert = false;
                            break;
                        }
                        else if(!(palya[oszlop][sor] == palya[oszlop+oszlop_differencia+j][sor+sor_differencia-j]))
                        {
                            nyert = false;
                            break;
                        }
                    }
                    if(nyert)
                        {
                            for(int j = 0;j<4;j++)
                            {
                              palya[oszlop+oszlop_differencia+j][sor+sor_differencia-j] += 2;
                            }
                            return nyert;
                        }
                }
                continue;
            case rakott:
                {
                }
                continue;
        }
    }
    return false;
}
