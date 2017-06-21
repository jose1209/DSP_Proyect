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

void filtro::setCoefieciente(float _a0_E1,float _a1_E1,float _a2_E1,float _b0_E1,float _b1_E1,float _b2_E1,float _k_E1,
                             float _a0_E2,float _a1_E2,float _a2_E2,float _b0_E2,float _b1_E2,float _b2_E2,float _k_E2,
                             float _a0_E3,float _a1_E3,float _a2_E3,float _b0_E3,float _b1_E3,float _b2_E3,float _k_E3
                             ){

    a0_E1 = _a0_E1;
    a1_E1 = _a1_E1;
    a2_E1 = _a2_E1;
    b0_E1 = _b0_E1;
    b1_E1 = _b1_E1;
    b2_E1 = _b2_E1;
    k0_E1 = _k_E1;
    a0_E2 = _a0_E2;
    a1_E2 = _a1_E2;
    a2_E2 = _a2_E2;
    b0_E2 = _b0_E2;
    b1_E2 = _b1_E2;
    b2_E2 = _b2_E2;
    k0_E2 = _k_E2;
    a0_E3 = _a0_E3;
    a1_E3 = _a1_E3;
    a2_E3 = _a2_E3;
    b0_E3 = _b0_E3;
    b1_E3 = _b1_E3;
    b2_E3 = _b2_E3;
    k0_E3 = _k_E3;
}

void filtro::filter(int blockSize, int volumeGain, float *in,float *inA,float *out){
    float y_n_menos_1 = 0;
    float y_n_menos_2 = 0;
    float x_n_menos_1 = 0;
    float x_n_menos_2 = 0;
    float a_n_menos_1 = 0;
    float a_n_menos_2 = 0;

    for (int n=0; n<blockSize;++n){

        float outA = k0_E1*a0_E1*in[n]- a1_E1*(y_n_menos_1) - a2_E1*(y_n_menos_2);
        float outB = b0_E1*outA + b1_E1*(y_n_menos_1) + b2_E1*(y_n_menos_2);

        y_n_menos_2 = y_n_menos_1;
        y_n_menos_1 = outA;

        float outC = k0_E2*a0_E2*(outB)- a1_E2*(x_n_menos_1) - a2_E2*(x_n_menos_2);
        float outD = b0_E2*outC + b1_E2*(x_n_menos_1) + b2_E2*(x_n_menos_2);

        x_n_menos_2 = x_n_menos_1;
        x_n_menos_1 = outC;

        float outE = k0_E3*a0_E3*(outD)- a1_E3*(a_n_menos_1) - a2_E3*(a_n_menos_2);
        float outF = b0_E3*outE + b1_E3*(a_n_menos_1) + b2_E3*(a_n_menos_2);

        a_n_menos_2 = a_n_menos_1;
        a_n_menos_1 = outE;

        float filtrado = outF*(volumeGain)*0.1;
        out[n] = filtrado + inA[n];

    }
}

