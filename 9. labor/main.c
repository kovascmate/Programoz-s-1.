#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

char* masolat(char *szoveg)
{
    //a program megkap egy char pointert mely egy stringet képvisel, a program megkeresi a lezáró nullát, majd másolja
    int hossz = 0;
    int szaml = 0;
    for(int i = 0; szoveg[i] != '\0';i++)
    {
        szaml++;
    }
    szaml++;
    char *masolat = (char*) malloc(szaml*sizeof(char));
    for(int i = 0; i < szaml;i++)
    {
        masolat[i] = szoveg[i];
    }

    return masolat;
}

void harmasf()
{
    char *masodik;
    char szoveg[] = "asdASDasd";
    masodik = masolat(szoveg);
    for(int i = 0; masodik[i] != '\0';i++)
    {
        printf("%c",masodik[i]);
    }
    printf("\n");
    free(masodik);
}
char* hozzafuz(char *elso,char *masodik)
{
    //megkap két pontert, melyek stringeket takarnak, majd összeolvassza oket, mereteket megkeresi, majd a megfelelo helyen elkezdi az elso string után irni a másodikat
    int szaml = 0;

    int szaml2 = 0;
    for(int i = 0;elso[i] != '\0';i++)
    {
        szaml++;
    }
    for(int i = 0;elso[i] != '\0';i++)
    {
        szaml2++;
    }
    char *uj = (char*) malloc((szaml+szaml2+2)*sizeof(char));
    for(int i = 0; i<szaml;i++)
    {
        uj[i] = elso[i];
    }
    for(int i = szaml;i<szaml2+szaml;i++)
    {
        uj[i] = masodik[i-szaml];
    }
    uj[szaml+szaml2+1] = '\0';
    free(elso);
    return uj;
}

void negyesf()
{
        char *x = masolat("alma");
        x = hozzafuz(x, "fa");
        printf("%s\n", x);
        free(x);
}
char* resz(char *szoveg)
{
    //a függvény kapja egy string pointerét, majd bekér két számot és a két szám közötti részt kiirja
    printf("Elso valasztas:");
    int egy = 0;
    scanf("%d",&egy);

    printf("Masodik valasztas:");
    int ketto = 0;
    scanf("%d",&ketto);

    if(egy < 0)
    {
        egy = 1;
    }
    int szaml = 0;
    for(int i = 0; szoveg[i] != '\0';i++)
    {
        szaml++;
    }
    if(szaml<ketto)
    {
        ketto=szaml+1;
    }
    int p = 0;
    char *uj = (char*) malloc((ketto-egy+1)*sizeof(char));
    for(int i = egy-1;i<ketto-1;i++)
    {
        uj[p] = szoveg[i];
        p++;
    }
    uj[p] = '\0';
    return uj;
}
void otosf()
{
    char alap[] = "almafa";
    int k = 0;
    printf("%s\n",alap);
    char *uj = resz(alap);
    printf("%s",uj);
    free(uj);

}
char *lyukaszt(char *szoveg)
{
    //a függvény megkapja eg string pointerét, majd bekér két számot és a sting két számadik elemei közötti karaktereken kivül kiirja a stringet összefüzve
    printf("Elso valasztas:");
    int egy = 0;
    scanf("%d",&egy);
    printf("Masodik valasztas:");
    int ketto = 0;
    scanf("%d",&ketto);
    if(egy < 0)
    {
        egy = 0;
    }
    int szaml = 0;
    for(int i = 0; szoveg[i] != '\0';i++)
    {
        szaml++;
    }
    if(szaml<ketto)
    {
        ketto=szaml;
    }
    int p = 0;
    char *uj = (char*) malloc((egy+szaml-ketto+1)*sizeof(char));
    for(int i = 0; i <szaml;i++)
    {
        if(i < egy)
        {
            uj[p] = szoveg[i];
            p++;
        }
        if(i >=ketto)
        {
            uj[p] = szoveg[i];
            p++;
        }
    }
    uj[p] = '\0';
    return uj;
}
void hatosf()
{
    char szoveg[]= "almafa";
    printf("%s\n",szoveg);
    char *uj= lyukaszt(szoveg);
    printf("%s",uj);
    free(uj);
}

char *beszur(char *szoveg,int szam,char* be)
{
    //a függvény kap két string pointerét és egy számot, az elso string számadik karaktere után beszúrja a második stringet, majd utána folytatja az elso stringet
    int p = 0;
    int k = 0;
    for(int i = 0; szoveg[i] != '\0';i++)
    {
        p++;
    }
    for(int i = 0; be[i] != '\0';i++)
    {
        k++;
    }
    char* uj= (char*) malloc((k+p)*sizeof(char));
    for(int i = 0; i <szam;i++)
    {
        uj[i] = szoveg[i];
    }
    for(int i = 0;i <k;i++)
    {
        uj[szam+i] = be[i];
    }
    for(int i = 0;i <p-szam;i++)
    {
        uj[szam+k+i]=szoveg[szam+i];
    }
    return uj;
}
void hetesf()
{
   char alap[] = "kicsi almak";
   int szam = 5;
   char be[] = "k az";
   char *uj = beszur(alap,szam,be);
   printf("%s",uj);
   free(uj);
}
int main()
{
   //harmasf();
   //negyesf();
   //otosf();
   //hatosf();
   //hetesf();
    return 0;
}
