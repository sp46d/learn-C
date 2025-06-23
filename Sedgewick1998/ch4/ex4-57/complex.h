#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct complex* Complex;
Complex COMPLEXinit(float, float);
float Re(Complex);
float Im(Complex);
Complex COMPLEXadd(Complex, Complex);
Complex COMPLEXmult(Complex, Complex);

#endif
