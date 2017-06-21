#ifndef FILTRO_H
#define FILTRO_H

class filtro {

protected:

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

   float a0_E1,a1_E1,a2_E1,a0_E2,a1_E2,a2_E2,a0_E3,a1_E3,a2_E3;
   float b0_E1, b1_E1, b2_E1,b0_E2,b1_E2,b2_E2,b0_E3,b1_E3,b2_E3;
   float k0_E1,k0_E2,k0_E3;
   double xn;
   double outA;
   double outB;
   double outC;
   double outD;
   double outE;
   double outF;
   float filtrado[1024];

   void filter(int blockSize,
               int volumeGain,
               float* in,
               float* inA,
               float* out);

   //Seleciona los coeficientes para el filtro

   void setCoefieciente(float _a0_E1,float _a1_E1,float _a2_E1,float _b0_E1,float _b1_E1,float _b2_E1,float _k_E1,
                        float _a0_E2,float _a1_E2,float _a2_E2,float _b0_E2,float _b1_E2,float _b2_E2,float _k_E2,
                        float _a0_E3,float _a1_E3,float _a2_E3,float _b0_E3,float _b1_E3,float _b2_E3,float _k_E3
                        );

};
#endif // FILTRO_H
