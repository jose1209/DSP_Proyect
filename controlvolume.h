/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2017  Jose Miguel Barboza
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

/**
 * \file   controlVolume.h
 *         Implements control volumen in the time domain
 * \author Jose Miguel Barboza
 * \date   2017.31.05
 *
 * $Id: controlVolume.cpp $
 */


#ifndef CONTROLVOLUME_H
#define CONTROLVOLUME_H

/**
 * Control Volume class
 *
 * This filter has control in the volume gain of the signal.
 *
 * The filter follows the difference equation
 * \f[
 * y(n)=\cvGain x(n)
 * \f]
 */

class controlVolume {

protected:
    float y_n_menos_1, y_n_menos_2, y_n_menos_3, y_n_menos_4, y_n_menos_5, y_n_menos_6;
    float a1, a2, a3, a4, a5, a6;
    float x_n_menos_1, x_n_menos_2, x_n_menos_3, x_n_menos_4, x_n_menos_5, x_n_menos_6;
    float b0, b1, b2, b3, b4, b5, b6;



public:
    /**
     * Constructor
     */
    controlVolume();

    /**
     * Destructor
     */
    ~controlVolume();

   /**
    * Filter the in buffer and leave the result in out
    */




    void filter(int blockSize,
                int volumeGain,
                float* in,
                float* out);
    /*void inicializar ();*/
    void setCoefieciente(float _a1,
                         float _a2,
                         float _a3,
                         float _a4,
                         float _a5,
                         float _a6,
                         float _b0,
                         float _b1,
                         float _b2,
                         float _b3,
                         float _b4,
                         float _b5,
                         float _b6 );
};



#endif // CONTROLVOLUME_H




















