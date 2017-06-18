
#include "filtro_a.h"
#include <cmath>

/*
 * Constructor
 */

filtroA::filtroA(){

}

//Destructor

filtroA::~filtroA(){

}


//Estructura de lo que hace el filtro
//float* inT;
void filtroA::filterA(int blockSize, int volumeGain_filtroA, float *in,float *inA, float *out){
    for (int n=0; n<blockSize;++n){
        out[n]=(volumeGain_filtroA)*(in[n] + inA[n])*0.02;
    }
}
