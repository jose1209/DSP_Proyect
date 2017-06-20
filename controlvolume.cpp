/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2017  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * \file   controlVolume.cpp
 *         Implements control volumen in the time domain
 * \author Jose Miguel Barboza
 * \date   2017.31.05
 *
 * $Id: controlVolume.cpp $
 */

#include "controlvolume.h"
#include <cmath>

/*
 * Constructor
 */

controlVolume::controlVolume(){

}


/*
 * Destructor
 */

controlVolume::~controlVolume(){

}


/*
 * Init the filter operation
 */

void controlVolume::setCoefieciente(float _a1, float _a2, float _a3, float _a4, float _a5, float _a6 ,float _b0, float _b1, float _b2, float _b3, float _b4, float _b5, float _b6 ){
    a1=_a1;
    a2=_a2;
    a3=_a3;
    a4=_a4;
    a5=_a5;
    a6=_a6;
    b0=_b0;
    b1=_b1;
    b2=_b2;
    b3=_b3;
    b4=_b4;
    b5=_b5;
    b6=_b6;
}
void controlVolume::filter(int blockSize, int volumeGain, float *in, float *out){
    for (int n=0; n<blockSize;++n){
        out[n]= (0.9)*(b0*in[n] + (b1)*(x_n_menos_1) + (b2)*(x_n_menos_2) + (b3)*(x_n_menos_3) + (b4)*(x_n_menos_4) + (b5)*(x_n_menos_5) + (b6)*(x_n_menos_6) + (a1)*(y_n_menos_1) + (a2)*(y_n_menos_2) + (a3)*(y_n_menos_3) + (a4)*(y_n_menos_4) + (a5)*(y_n_menos_5) + (a6)*(y_n_menos_6));

        x_n_menos_6= x_n_menos_5;
        x_n_menos_5= x_n_menos_4;
        x_n_menos_4= x_n_menos_3;
        x_n_menos_3= x_n_menos_2;
        x_n_menos_2= x_n_menos_1;
        x_n_menos_1= in[n];




        y_n_menos_6= y_n_menos_5;
        y_n_menos_5= y_n_menos_4;
        y_n_menos_4= y_n_menos_3;
        y_n_menos_3= y_n_menos_2;
        y_n_menos_2= y_n_menos_1;
        y_n_menos_1= out[n];
    }
}
