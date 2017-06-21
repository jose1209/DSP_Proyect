/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2010  Pablo Alvarado
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
 * \file   freqFilter.h
 *         Implements filtering in the frequency domain
 * \author Pablo Alvarado/Jose Miguel Barboza
 * \date   2010.12.12/2017.05.26
 *
 * $Id: equalizer.cpp $
 */

#include "dspsystem.h"
#include <cstring>
#include <fftw3.h>
#undef _DSP_DEBUG
#define _DSP_DEBUG
#define REAL 0
#define IMAG 1
#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif

dspSystem::dspSystem():sampleRate_(0),bufferSize_(0),cv_(0),cvA_(0){
}

dspSystem::~dspSystem() {
    delete cv_;
    delete cvA_;
    cv_;
    cvA_;
}

//////////////////////Actualiza los Sliders///////////////////////////////////////
void dspSystem::updateVolume(int value){
   volumeGain_ = value;
}
void dspSystem::updateVolumeA(int value32Hz){
   volumeGain32Hz_ = value32Hz;
}
void dspSystem::updateVolumeB(int value64Hz){
   volumeGain64Hz_ = value64Hz;
}
void dspSystem::updateVolumeC(int value125Hz){
   volumeGain125Hz_ = value125Hz;

}
void dspSystem::updateVolumeD(int value250Hz){
   volumeGain250Hz_ = value250Hz;

}
void dspSystem::updateVolumeE(int value500Hz){
    volumeGain500Hz_ = value500Hz;

}
void dspSystem::updateVolumeF(int value1kHz){
    volumeGain1kHz_ = value1kHz;

}
void dspSystem::updateVolumeG(int value2kHz){
    volumeGain2kHz_ = value2kHz;

}
void dspSystem::updateVolumeH(int value4kHz){
    volumeGain4kHz_ = value4kHz;

}
void dspSystem::updateVolumeI(int value8kHz){
    volumeGain8kHz_ = value8kHz;

}
void dspSystem::updateVolumeJ(int value16kHz){
    volumeGain16kHz_ = value16kHz;

}
///////////////////////////////////////////////////////////////////////

//Constantes para los filtros//

//Filtro 32Hz ////////////////////////////////


float b0_32Hz_Etapa1 = 1;
float b1_32Hz_Etapa1 = -1.993853192589357;
float b2_32Hz_Etapa1 = 1;
float a0_32Hz_Etapa1 = 1;
float a1_32Hz_Etapa1 = -1.9965097193341501;
float a2_32Hz_Etapa1 = 0.99656070779774109;
float kA_32Hz_Etapa1 = 0.083975042421657473;

float b0_32Hz_Etapa2 = 1;
float b1_32Hz_Etapa2 = -1.9999999553121124;
float b2_32Hz_Etapa2 = 1;
float a0_32Hz_Etapa2 = 1;
float a1_32Hz_Etapa2 = -1.9988764466393667;
float a2_32Hz_Etapa2 = 0.99888182982847662;
float kA_32Hz_Etapa2 = 0.083975042421657473;

float b0_32Hz_Etapa3 = 1;
float b1_32Hz_Etapa3 = 0;
float b2_32Hz_Etapa3 = -1;
float a0_32Hz_Etapa3 = 1;
float a1_32Hz_Etapa3 = -1.9954095735453359;
float a2_32Hz_Etapa3 =  0.9954261220202798;
float kA_32Hz_Etapa3 = 0.0014366046699645517;

//Filtro 64Hz ///////////////////////////////

float b0_64Hz_Etapa1 = 1;
float b1_64Hz_Etapa1 = -1.9755248962969771;
float b2_64Hz_Etapa1 = 1;
float a0_64Hz_Etapa1 = 1;
float a1_64Hz_Etapa1 = -1.9929297702093247;
float a2_64Hz_Etapa1 = 0.99313337029040205;
float kA_64Hz_Etapa1 = 0.084070843137905707;

float b0_64Hz_Etapa2 = 1;
float b1_64Hz_Etapa2 = -1.9999998212496854;
float b2_64Hz_Etapa2 = 1;
float a0_64Hz_Etapa2 = 1;
float a1_64Hz_Etapa2 = -1.9977433818714319;
float a2_64Hz_Etapa2 = 0.99776490251424721;
float kA_64Hz_Etapa2 = 0.084070843137905707;

float b0_64Hz_Etapa3 = 1;
float b1_64Hz_Etapa3 = 0;
float b2_64Hz_Etapa3 = -1;
float a0_64Hz_Etapa3 = 1;
float a1_64Hz_Etapa3 = -1.9908070551031405;
float a2_64Hz_Etapa3 = 0.99087309782936328;
float kA_64Hz_Etapa3 = 0.0028666593946716969;

//Filtro 125Hz  ////////////////////////////

float b0_125Hz_Etapa1 = 1;
float b1_125Hz_Etapa1 = -1.9017183920532552;
float b2_125Hz_Etapa1 = 1;
float a0_125Hz_Etapa1 = 1;
float a1_125Hz_Etapa1 = -1.9853065556456944;
float a2_125Hz_Etapa1 = 0.98613006471327724;
float kA_125Hz_Etapa1 = 0.084658045606493496;

float b0_125Hz_Etapa2 = 1;
float b1_125Hz_Etapa2 = -1.9999992929689627;
float b2_125Hz_Etapa2 = 1;
float a0_125Hz_Etapa2 = 1;
float a1_125Hz_Etapa2 = -1.9954291339009194;
float a2_125Hz_Etapa2 = 0.9955148277693523;
float kA_125Hz_Etapa2 = 0.084658045606493496;

float b0_125Hz_Etapa3 = 1;
float b1_125Hz_Etapa3 = 0;
float b2_125Hz_Etapa3 = -1;
float a0_125Hz_Etapa3 = 1;
float a1_125Hz_Etapa3 = -1.9813599363260852;
float a2_125Hz_Etapa3 = 0.98162437184721885;
float kA_125Hz_Etapa3 = 0.0057715823060572984;


//Filtro 250Hz ////////////////////////////////

float b0_250Hz_Etapa1 = 1;
float b1_250Hz_Etapa1 = -1.6336902993552394;
float b2_250Hz_Etapa1 = 1;
float a0_250Hz_Etapa1 = 1;
float a1_250Hz_Etapa1 = -1.9692073728561379;
float a2_250Hz_Etapa1 = 0.9724907465435072;
float kA_250Hz_Etapa1 = 0.087294357811615708;

float b0_250Hz_Etapa2 = 1;
float b1_250Hz_Etapa2 = -1.9999971239785066;
float b2_250Hz_Etapa2 = 1;
float a0_250Hz_Etapa2 = 1;
float a1_250Hz_Etapa2 = -1.990672163454865;
float a2_250Hz_Etapa2 = 0.99101863178130989;
float kA_250Hz_Etapa2 = 0.087294357811615708;

float b0_250Hz_Etapa3 = 1;
float b1_250Hz_Etapa3 = 0;
float b2_250Hz_Etapa3 = -1;
float a0_250Hz_Etapa3 = 1;
float a1_250Hz_Etapa3 = -1.962525111150814;
float a2_250Hz_Etapa3 =  0.96358212003341437;
float kA_250Hz_Etapa3 = 0.01143845477780045;


//Filtro 500Hz/////////////////////////////////

float b0_500Hz_Etapa1 = 1;
float b1_500Hz_Etapa1 = -0.85357686525427923;
float b2_500Hz_Etapa1 = 1;
float a0_500Hz_Etapa1 = 1;
float a1_500Hz_Etapa1 = -1.9330871236219007;
float a2_500Hz_Etapa1 = 0.94600733097579404;
float kA_500Hz_Etapa1 = 0.097489445917318784;

float b0_500Hz_Etapa2 = 1;
float b1_500Hz_Etapa2 = -1.9999883723177025;
float b2_500Hz_Etapa2 = 1;
float a0_500Hz_Etapa2 = 1;
float a1_500Hz_Etapa2 = -1.98071416814503;
float a2_500Hz_Etapa2 = 0.98210365605720462;
float kA_500Hz_Etapa2 = 0.097489445917318784;


float b0_500Hz_Etapa3 = 1;
float b1_500Hz_Etapa3 = 0;
float b2_500Hz_Etapa3 = -1;
float a0_500Hz_Etapa3 = 1;
float a1_500Hz_Etapa3 = -1.9244872949121987;
float a2_500Hz_Etapa3 = 0.92865128345449877;
float kA_500Hz_Etapa3 = 0.022409845614534157;



//Filtro 1kHz//////////////////////////////////

float b0_1kHz_Etapa1 = 1;
float b1_1kHz_Etapa1 = 0.47279717988314574;
float b2_1kHz_Etapa1 = 1;
float a0_1kHz_Etapa1 = 1;
float a1_1kHz_Etapa1 = -1.845303655939885;
float a2_1kHz_Etapa1 = 0.89540566775691588;
float kA_1kHz_Etapa1 = 0.13021231629593022;

float b0_1kHz_Etapa2 = 1;
float b1_1kHz_Etapa2 = -1.9999535888290165;
float b2_1kHz_Etapa2 = 1;
float a0_1kHz_Etapa2 = 1;
float a1_1kHz_Etapa2 = -1.9589943864484209;
float a2_1kHz_Etapa2 = 0.96449778468920166;
float kA_1kHz_Etapa2 = 0.13021231629593022;


float b0_1kHz_Etapa3 = 1;
float b1_1kHz_Etapa3 = 0;
float b2_1kHz_Etapa3 = -1;
float a0_1kHz_Etapa3 = 1;
float a1_1kHz_Etapa3 = -1.8460755869288992;
float a2_1kHz_Etapa3 = 0.86214853907733413;
float kA_1kHz_Etapa3 = 0.04329762477289735;

//Filtro 2kHz  //////////////////////////////

float b0_2kHz_Etapa1 = 1;
float b1_2kHz_Etapa1 = 1.478902086634897;
float b2_2kHz_Etapa1 = 1;
float a0_2kHz_Etapa1 = 1;
float a1_2kHz_Etapa1 = -1.6178046105352717;
float a2_2kHz_Etapa1 = 0.80514958338784515;
float kA_2kHz_Etapa1 = 0.21091936442384895;

float b0_2kHz_Etapa2 = 1;
float b1_2kHz_Etapa2 = -1.9998159415472905;
float b2_2kHz_Etapa2 = 1;
float a0_2kHz_Etapa2 = 1;
float a1_2kHz_Etapa2 = -1.9084796919927434;
float a2_2kHz_Etapa2 = 0.93002535141504239;
float kA_2kHz_Etapa2 = 0.21091936442384895;


float b0_2kHz_Etapa3 = 1;
float b1_2kHz_Etapa3 = 0;
float b2_2kHz_Etapa3 = -1;
float a0_2kHz_Etapa3 = 1;
float a1_2kHz_Etapa3 = -1.6815883771972273;
float a2_2kHz_Etapa3 = 0.74158801013609332;
float kA_2kHz_Etapa3 = 0.0811643583539675;


//Filtro 4kHz  //////////////////////////////

float b0_4kHz_Etapa1 = 1;
float b1_4kHz_Etapa1 = 1.871893335353092;
float b2_4kHz_Etapa1 = 1;
float a0_4kHz_Etapa1 = 1;
float a1_4kHz_Etapa1 = -1.0255010595692862;
float a2_4kHz_Etapa1 = 0.67004607742103039;
float kA_4kHz_Etapa1 = 0.36785749762097808;

float b0_4kHz_Etapa2 = 1;
float b1_4kHz_Etapa2 = -1.9992887209022334;
float b2_4kHz_Etapa2 = 1;
float a0_4kHz_Etapa2 = 1;
float a1_4kHz_Etapa2 = -1.7812843034742643;
float a2_4kHz_Etapa2 = 0.86321381274185804;
float kA_4kHz_Etapa2 = 0.36785749762097808;


float b0_4kHz_Etapa3 = 1;
float b1_4kHz_Etapa3 = 0;
float b2_4kHz_Etapa3 = -1;
float a0_4kHz_Etapa3 = 1;
float a1_4kHz_Etapa3 = -1.3289399355293408;
float a2_4kHz_Etapa3 = 0.53922508798951962;
float kA_4kHz_Etapa3 = 0.14472432219043893;



//Filtro 8kHz  //////////////////////////////

float b0_8kHz_Etapa1 = 1;
float b1_8kHz_Etapa1 =1.9808473574607248;
float b2_8kHz_Etapa1 = 1;
float a0_8kHz_Etapa1 = 1;
float a1_8kHz_Etapa1 = -1.4475229357214379;
float a2_8kHz_Etapa1 = 0.73283494197771648;
float kA_8kHz_Etapa1 = 0.73283494197771648;

float b0_8kHz_Etapa2 = 1;
float b1_8kHz_Etapa2 = -1.9975279181112393;
float b2_8kHz_Etapa2 = 1;
float a0_8kHz_Etapa2 = 1;
float a1_8kHz_Etapa2 = 0.27882464276596969;
float a2_8kHz_Etapa2 = 0.56740596543677824;
float kA_8kHz_Etapa2 = 0.61460817304778603;


float b0_8kHz_Etapa3 = 1;
float b1_8kHz_Etapa3 = 0;
float b2_8kHz_Etapa3 = -1;
float a0_8kHz_Etapa3 = 1;
float a1_8kHz_Etapa3 = -0.58271906798865447;
float a2_8kHz_Etapa3 = 0.2340666187320094;
float kA_8kHz_Etapa3 = 0.24057123458258006;


//Filtro 16kHz  //////////////////////////////

float b0_16kHz_Etapa1 = 1;
float b1_16kHz_Etapa1 = -1.9946288061772268;
float b2_16kHz_Etapa1 = 1;
float a0_16kHz_Etapa1 = 1;
float a1_16kHz_Etapa1 = 1.9112119599948862;
float a2_16kHz_Etapa1 = 0.9205767213208782;
float kA_16kHz_Etapa1 = 0.91900519525219959;

float b0_16kHz_Etapa2 = 1;
float b1_16kHz_Etapa2 = 1.9999551487968634;
float b2_16kHz_Etapa2 = 1;
float a0_16kHz_Etapa2 = 1;
float a1_16kHz_Etapa2 = -0.80929608889125348;
float a2_16kHz_Etapa2 = 0.48030962763453239;
float kA_16kHz_Etapa2 = 0.91900519525219959;


float b0_16kHz_Etapa3 = 1;
float b1_16kHz_Etapa3 = 0;
float b2_16kHz_Etapa3 = -1;
float a0_16kHz_Etapa3 = 1;
float a1_16kHz_Etapa3 = 0.67589368035552611;
float a2_16kHz_Etapa3 = -0.18825641449701139;
float kA_16kHz_Etapa3 = 0.37321824538183573;


/////////////////////////////////////////////////

/**
 * Initialization function for the current filter plan
 */
bool dspSystem::init(const int sampleRate,const int bufferSize) {
  _debug("dspSystem::init()" << std::endl);

  sampleRate_ = sampleRate;
  bufferSize_ = bufferSize;
  volumeGain_ = 0;
  volumeGain32Hz_ = 0;
  volumeGain64Hz_ = 0;
  volumeGain125Hz_ = 0;
  volumeGain250Hz_ = 0;
  volumeGain500Hz_ = 0;
  volumeGain1kHz_ = 0;
  volumeGain2kHz_ = 0;
  volumeGain4kHz_ = 0;
  volumeGain8kHz_ = 0;
  volumeGain16kHz_ = 0;

  delete cv_;
  delete cvA_;
  cv_ = new controlVolume();      //Volumen General
  cvA_ = new filtro();           //Para el Filtro

  return true;
}
/*
float dspSystem::fourier(int bufferSize, double* pfout){

    int n = bufferSize;
    fftwf_complex x[n];
    fftwf_complex y[n];
    for(int i = 0;i<n;i++){
        x[i][REAL] = pfout[i];
        x[i][IMAG] = 0;
    }
    fftw_plan plan;
    plan = fftw_plan_dft_1d(n,x,y,FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(plan);

    fftw_destroy_plan(plan);
    fftw_cleanup();

}*/

/**
 * Processing function
 */
bool dspSystem::process(float* in,float* out) {

  float* tmpIn = in;
  float* tmpOut = out;
  float aux[1024]={};
  float* tmpaux = aux;



/////////////////////////////////////////////////Filtro 32Hz//////////////////////////////////////////////////////////
  cvA_->setCoefieciente(a0_32Hz_Etapa1, a1_32Hz_Etapa1, a2_32Hz_Etapa1, b0_32Hz_Etapa1, b1_32Hz_Etapa1, b2_32Hz_Etapa1, kA_32Hz_Etapa1,
                        a0_32Hz_Etapa2, a1_32Hz_Etapa2, a2_32Hz_Etapa2, b0_32Hz_Etapa2, b1_32Hz_Etapa2, b2_32Hz_Etapa2, kA_32Hz_Etapa2,
                        a0_32Hz_Etapa3, a1_32Hz_Etapa3, a2_32Hz_Etapa3, b0_32Hz_Etapa3, b1_32Hz_Etapa3, b2_32Hz_Etapa3, kA_32Hz_Etapa3
                        );
  cvA_->filter(bufferSize_,volumeGain32Hz_,tmpIn,aux,tmpaux);
//fourier(bufferSize_,tmpaux);
/////////////////////////////////////////////////Filtro 64Hz//////////////////////////////////////////////////////////
  cvA_->setCoefieciente(a0_64Hz_Etapa1, a1_64Hz_Etapa1, a2_64Hz_Etapa1, b0_64Hz_Etapa1, b1_64Hz_Etapa1, b2_64Hz_Etapa1, kA_64Hz_Etapa1,
                        a0_64Hz_Etapa2, a1_64Hz_Etapa2, a2_64Hz_Etapa2, b0_64Hz_Etapa2, b1_64Hz_Etapa2, b2_64Hz_Etapa2, kA_64Hz_Etapa2,
                        a0_64Hz_Etapa3, a1_64Hz_Etapa3, a2_64Hz_Etapa3, b0_64Hz_Etapa3, b1_64Hz_Etapa3, b2_64Hz_Etapa3, kA_64Hz_Etapa3
                        );
  cvA_->filter(bufferSize_,volumeGain64Hz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 125Hz//////////////////////////////////////////////////////////
  cvA_->setCoefieciente(a0_125Hz_Etapa1, a1_125Hz_Etapa1, a2_125Hz_Etapa1, b0_125Hz_Etapa1, b1_125Hz_Etapa1, b2_125Hz_Etapa1, kA_125Hz_Etapa1,
                        a0_125Hz_Etapa2, a1_125Hz_Etapa2, a2_125Hz_Etapa2, b0_125Hz_Etapa2, b1_125Hz_Etapa2, b2_125Hz_Etapa2, kA_125Hz_Etapa2,
                        a0_125Hz_Etapa3, a1_125Hz_Etapa3, a2_125Hz_Etapa3, b0_125Hz_Etapa3, b1_125Hz_Etapa3, b2_125Hz_Etapa3, kA_125Hz_Etapa3
                        );
    cvA_->filter(bufferSize_,volumeGain125Hz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 250Hz//////////////////////////////////////////////////////////
    cvA_->setCoefieciente(a0_250Hz_Etapa1, a1_250Hz_Etapa1, a2_250Hz_Etapa1, b0_250Hz_Etapa1, b1_250Hz_Etapa1, b2_250Hz_Etapa1, kA_250Hz_Etapa1,
                          a0_250Hz_Etapa2, a1_250Hz_Etapa2, a2_250Hz_Etapa2, b0_250Hz_Etapa2, b1_250Hz_Etapa2, b2_250Hz_Etapa2, kA_250Hz_Etapa2,
                          a0_250Hz_Etapa3, a1_250Hz_Etapa3, a2_250Hz_Etapa3, b0_250Hz_Etapa3, b1_250Hz_Etapa3, b2_250Hz_Etapa3, kA_250Hz_Etapa3
                          );
        cvA_->filter(bufferSize_,volumeGain250Hz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 500Hz//////////////////////////////////////////////////////////
     cvA_->setCoefieciente(a0_500Hz_Etapa1, a1_500Hz_Etapa1, a2_500Hz_Etapa1, b0_500Hz_Etapa1, b1_500Hz_Etapa1, b2_500Hz_Etapa1, kA_500Hz_Etapa1,
                           a0_500Hz_Etapa2, a1_500Hz_Etapa2, a2_500Hz_Etapa2, b0_500Hz_Etapa2, b1_500Hz_Etapa2, b2_500Hz_Etapa2, kA_500Hz_Etapa2,
                           a0_500Hz_Etapa3, a1_500Hz_Etapa3, a2_500Hz_Etapa3, b0_500Hz_Etapa3, b1_500Hz_Etapa3, b2_500Hz_Etapa3, kA_500Hz_Etapa3
                           );
     cvA_->filter(bufferSize_,volumeGain500Hz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 1000Hz//////////////////////////////////////////////////////////
     cvA_->setCoefieciente(a0_1kHz_Etapa1, a1_1kHz_Etapa1, a2_1kHz_Etapa1, b0_1kHz_Etapa1, b1_1kHz_Etapa1, b2_1kHz_Etapa1, kA_1kHz_Etapa1,
                           a0_1kHz_Etapa2, a1_1kHz_Etapa2, a2_1kHz_Etapa2, b0_1kHz_Etapa2, b1_1kHz_Etapa2, b2_1kHz_Etapa2, kA_1kHz_Etapa2,
                           a0_1kHz_Etapa3, a1_1kHz_Etapa3, a2_1kHz_Etapa3, b0_1kHz_Etapa3, b1_1kHz_Etapa3, b2_1kHz_Etapa3, kA_1kHz_Etapa3
                           );
     cvA_->filter(bufferSize_,volumeGain1kHz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 2000Hz//////////////////////////////////////////////////////////
     cvA_->setCoefieciente(a0_2kHz_Etapa1, a1_2kHz_Etapa1, a2_2kHz_Etapa1, b0_2kHz_Etapa1, b1_2kHz_Etapa1, b2_2kHz_Etapa1, kA_2kHz_Etapa1,
                           a0_2kHz_Etapa2, a1_2kHz_Etapa2, a2_2kHz_Etapa2, b0_2kHz_Etapa2, b1_2kHz_Etapa2, b2_2kHz_Etapa2, kA_2kHz_Etapa2,
                           a0_2kHz_Etapa3, a1_2kHz_Etapa3, a2_2kHz_Etapa3, b0_2kHz_Etapa3, b1_2kHz_Etapa3, b2_2kHz_Etapa3, kA_2kHz_Etapa3
                           );
     cvA_->filter(bufferSize_,volumeGain2kHz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 4000Hz//////////////////////////////////////////////////////////
     cvA_->setCoefieciente(a0_4kHz_Etapa1, a1_4kHz_Etapa1, a2_4kHz_Etapa1, b0_4kHz_Etapa1, b1_4kHz_Etapa1, b2_4kHz_Etapa1, kA_4kHz_Etapa1,
                           a0_4kHz_Etapa2, a1_4kHz_Etapa2, a2_4kHz_Etapa2, b0_4kHz_Etapa2, b1_4kHz_Etapa2, b2_4kHz_Etapa2, kA_4kHz_Etapa2,
                           a0_4kHz_Etapa3, a1_4kHz_Etapa3, a2_4kHz_Etapa3, b0_4kHz_Etapa3, b1_4kHz_Etapa3, b2_4kHz_Etapa3, kA_4kHz_Etapa3
                           );
     cvA_->filter(bufferSize_,volumeGain4kHz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 8000Hz//////////////////////////////////////////////////////////
     cvA_->setCoefieciente(a0_8kHz_Etapa1, a1_8kHz_Etapa1, a2_8kHz_Etapa1, b0_8kHz_Etapa1, b1_8kHz_Etapa1, b2_8kHz_Etapa1, kA_8kHz_Etapa1,
                           a0_8kHz_Etapa2, a1_8kHz_Etapa2, a2_8kHz_Etapa2, b0_8kHz_Etapa2, b1_8kHz_Etapa2, b2_8kHz_Etapa2, kA_8kHz_Etapa2,
                           a0_8kHz_Etapa3, a1_8kHz_Etapa3, a2_8kHz_Etapa3, b0_8kHz_Etapa3, b1_8kHz_Etapa3, b2_8kHz_Etapa3, kA_8kHz_Etapa3
                           );
     cvA_->filter(bufferSize_,volumeGain8kHz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////Filtro 16000Hz//////////////////////////////////////////////////////////
     cvA_->setCoefieciente(a0_16kHz_Etapa1, a1_16kHz_Etapa1, a2_16kHz_Etapa1, b0_16kHz_Etapa1, b1_16kHz_Etapa1, b2_16kHz_Etapa1, kA_16kHz_Etapa1,
                           a0_16kHz_Etapa2, a1_16kHz_Etapa2, a2_16kHz_Etapa2, b0_16kHz_Etapa2, b1_16kHz_Etapa2, b2_16kHz_Etapa2, kA_16kHz_Etapa2,
                           a0_16kHz_Etapa3, a1_16kHz_Etapa3, a2_16kHz_Etapa3, b0_16kHz_Etapa3, b1_16kHz_Etapa3, b2_16kHz_Etapa3, kA_16kHz_Etapa3
                           );
     cvA_->filter(bufferSize_,volumeGain16kHz_,tmpIn,aux,tmpaux);

/////////////////////////////////////////////////////Salida///////////////////////////////////////////////////////
     cv_->filter(bufferSize_,volumeGain_,tmpIn,aux,tmpOut);

/////////////////////////////////////////////////////////////////////////////////////////////////
  return true;
}

/*// Set N to the number of complex elements in the input array

  fftw_complex tmpOut, *filtro_32;

  tmpOut = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
  filtro_32 = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
*/
/**
 * Shutdown the processor
 */
bool dspSystem::shutdown() {
  return true;
}

/**
 * Set buffer size (call-back)
 */
int dspSystem::setBufferSize(const int bufferSize) {
  bufferSize_=bufferSize;
  return 1;
}

/**
 * Set sample rate (call-back)
 */
int dspSystem::setSampleRate(const int sampleRate) {
  sampleRate_=sampleRate;
  return 1;
}
