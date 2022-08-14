#include <stdio.h>

typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);

int main() {
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };
    printf("A 0. versenyzo neve: %s\n",versenyzok[0].nev);
    printf("A 2. versenyzo helyezese: %d volt\n",versenyzok[2].helyezes);
    printf("Az 1. versenyzo nevenek kezdo betuje:%c\n",versenyzok[1].nev[0]);
    datum_kiir(versenyzok[4].szuletes);
    printf("%s",versenyzok[1].helyezes<4 ? "Igen,dobogos lett az elso versenyzo\n":"Nem, nem lett dobogos az elso versenyzo\n");
    printf("%s",versenyzok[4].helyezes<versenyzok[3].helyezes? "A negyes versenyzo gyorsabb mint a harmas\n":"A harmas versenyzo gyorsabb mint a negyes\n");
    printf("%s",versenyzok[1].szuletes.ev=versenyzok[2].szuletes.ev? "Az egyes es a kettes versenyzo egy evben szuletett\n":"Az egyes es a kettes versenyzo nem egy evben szuletett\n");
    versenyzo_kiir(versenyzok[1]);
    for(int i = 0; i < 5;i++)
    {
        printf("\nSzamozas:%d\t",i);
        versenyzo_kiir(versenyzok[i]);
    }

    return 0;
}
void datum_kiir(Datum d) {
    printf("%d %d %d\n",d.ev,d.ho,d.nap);
}
void versenyzo_kiir(Versenyzo v) {
    printf("Neve:\t%s\tHelyezese:%d\tSzuletesi ideje:%d %d %d",v.nev,v.helyezes,v.szuletes.ev,v.szuletes.ho,v.szuletes.nap);
}

