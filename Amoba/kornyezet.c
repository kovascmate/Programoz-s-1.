#include "kornyezet.h"
//a range tömb fontos szerepet tölt be az "ellenorzes" és a "nehez" függvényben
//range tömb felépítése
//oszlop, sor, érték a ellemzéshez, ellenõrzés iránya
int range[25][4]={-3,-3,3,jobbra_le,/*1*/0,-3,3,le,/*2*/+3,-3,3,balra_le,/*3*//*1. sor*/-2,-2,2,jobbra_le,/*4*/0,-2,2,le,/*5*/+2,-2,2,balra_le,/*6*//*2. sor*/-1,-1,1,jobbra_le,/*7*/0,-1,1,le,/*8*/+1,-1,1,balra_le,/*9*//*3.sor*/-3,0,3,vizszintesen_jobbra,/*10*/-2,0,2,vizszintesen_jobbra,/*11*/-1,0,1,vizszintesen_jobbra,/*12*/0,0,5,rakott,/*13*/+1,0,1,vizszintesen_balra,/*14*/+2,0,2,vizszintesen_balra,/*15*/+3,0,3,vizszintesen_balra,/*16*//*4. sor*/+3,+3,3,balra_fel,/*17*/0,+3,3,fel,/*18*/-3,+3,3,jobbra_fel,/*19*//*5. sor*/+2,+2,2,balra_fel,/*20*/0,+2,2,fel,/*21*/-2,+2,2,jobbra_fel,/*22*//*6. sor*/+1,+1,1,balra_fel,/*23*/0,+1,1,fel,/*24*/-1,+1,1,jobbra_fel/*25*//*7.sor*/};
