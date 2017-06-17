



#include "filtroprueba.h"
#include <cmath>

filtroprueba::filtroprueba()
{

}


/**
 * \file   FiltroPrueba.cpp
 *         Implementar filtro prueba
 * \author Mr. Robot
 * \date   2017
 *
 * $Id: filtroprueba.cpp $
 */



/*
 * Constructor
 */

filtroprueba::filtroprueba(){

}


/*
 * Destructor
 */

filtroprueba::~filtroprueba(){

}


/*
 * Init the filter operation
 */

void filtroprueba::filter(int blockSize, int volumeGain, float *in, float *out){

    for (int n=0; n<blockSize;++n){
        out[n]=(volumeGain)*in[n]*0.02;
    }

}
