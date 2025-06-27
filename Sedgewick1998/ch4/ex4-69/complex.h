#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex* Complex;
Complex COMPLEXinit(int, int);
int Re(Complex);
int Im(Complex);
Complex COMPLEXadd(Complex, Complex);
Complex COMPLEXmult(Complex, Complex);
void COMPLEXprint(Complex);

#endif
