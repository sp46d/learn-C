#ifndef POLY_H
#define POLY_H

typedef struct poly* Poly;
void showPOLY(Poly);
Poly POLYterm(int, int);
Poly POLYcreate(int, ...);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
double POLYeval(Poly, double);

#endif
