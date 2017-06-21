#ifndef FILTRO_H
#define FILTRO_H

class filtro {

protected:
    //float volfilt1, volfilt2, volfilt3, volfilt4, volfilt5, volfilt6, volfilt7, volfilt8, volfilt9, ampfilt10;
    //Aqui se definen los atributos que va a tener el filtro, se utiliza uno de orden 2 en forma directa 2
    float y_n_menos_1, y_n_menos_2;
    float a0,a1,a2;
    float b0, b1, b2;
    float k;

public:
    /**
     * Constructor
     */
    filtro();

    /**
     * Destructor
     */
    ~filtro();

   /**
    * Filter the in buffer and leave the result in out
    */

   void filter(int blockSize,
               int volumeGain,
               float* in,
               //float* inA,
               float* out);

   //Seleciona los coeficientes para el filtro

   void setCoefieciente(float _a0,
                        float _a1,
                        float _a2,
                        float _b0,
                        float _b1,
                        float _b2,
                        float _k
                        );
};

#endif // FILTRO_H
