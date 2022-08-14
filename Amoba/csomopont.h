#ifndef CSOMOPONT_H
#define CSOMOPONT_H
typedef enum Kimenetel{
    semmi,
    hibas_lepesek,
    megtelt,
    program_nyert,
    felhasznalo_nyert
}Kimenetel;
bool csomopont(int **palya, int meret,char *nev,int level);
#endif // CSOMOPONT_H
