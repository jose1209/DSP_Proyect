#include "filtro.h"
#include <cmath>

filtro::filtro(){

}

/*
 * Constructor
 */

/*
 * Destructor
 */

filtro::~filtro(){

}

void filtro::setCoefieciente(float _a0,float _a1,float _a2,float _b0,float _b1,float _b2,float _k){

    a0 = _a0;
    a1 = _a1;
    a2 = _a2;
    b0 = _b0;
    b1 = _b1;
    b2 = _b2;
    k = _k;
}

void filtro::filter(int blockSize, int volumeGain, float *in,float *out){

    y_n_menos_2 = 0;
    y_n_menos_1 = 0;
    float xn = 0.0;
    float outA = 0.0;
    float outB = 0.0;
    float filtrado[2048];

    for (int n=0; n<blockSize;++n){
        xn = in[n];
        outA = k*a0*(xn)- a1*(y_n_menos_1) - a2*(y_n_menos_2);
        outB = b0*outA + b1*(y_n_menos_1) + b2*(y_n_menos_2);
        filtrado[n] = outB*(volumeGain)*0.02;
        out[n] = filtrado[n];
        y_n_menos_2 = y_n_menos_1;
        y_n_menos_1 = outA;
    }
}

