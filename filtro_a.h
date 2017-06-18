#ifndef FILTRO_A_H
#define FILTRO_A_H

class filtroA{
public:
    /*constructor*/
    filtroA();

    /*destructor*/
    ~filtroA();

    void filterA(int blockSize,
                 int volumeGain_filtroA,
                 float* in,
                 float* inA,
                 float* out);

};


#endif // FILTRO_A_H
