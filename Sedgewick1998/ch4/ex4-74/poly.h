#ifndef POLY_H
#define POLY_H

// Max exponent; terms with exponent greater than or equal to M will be ignored
extern int M;

typedef struct poly* Poly;
void showPOLY(Poly);
Poly POLYterm(int, int);
Poly POLYcopy(Poly);
void POLYdestroy(Poly);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
Poly POLYintegral(Poly);
Poly POLYdiff(Poly);
float POLYeval(Poly, float);

#endif