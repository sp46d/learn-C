#ifndef POLY_H
#define POLY_H

typedef struct poly* Poly;
void showPOLY(Poly);
Poly POLYterm(float, int);
Poly POLYcopy(Poly);
void POLYdestroy(Poly);
Poly POLYadd(Poly, Poly);
Poly POLYsubtract(Poly, Poly);
Poly POLYmult(Poly, Poly);
Poly POLYdiv(Poly, Poly);
Poly POLYmod(Poly, Poly);
Poly POLYcomp(Poly, Poly);
Poly POLYintegral(Poly);
Poly POLYdiff(Poly);
float POLYeval(Poly, float);

#endif