


/**
 * \file   filtroprueba.h
 *         Implements filter
 * \author Mr. Robot
 * \date   2017
 *
 * $Id: filtroprueba.cpp $
 */


#ifndef FILTROPRUEBA_H
#define FILTROPRUEBA_H


class filtroprueba
{
public:
    filtroprueba();

    /**
     * Constructor
     */
    filtroprueba();

    /**
     * Destructor
     */
    ~filtroprueba();

   /**
    * Filter the in buffer and leave the result in out
    */
   void filter(int blockSize,
               int volumeGain,
               float* in,
               float* out);

};

#endif // FILTROPRUEBA_H
