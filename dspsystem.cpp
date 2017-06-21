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

#undef _DSP_DEBUG
#define _DSP_DEBUG

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
    volumeGain_ = value500Hz;

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
//////////////////////////////////////////////////////////////////////

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

//////algunas constantes///////////

float a0_32Hz_Etapa1 = 1;
float a1_32Hz_Etapa1 = 0;
float a2_32Hz_Etapa1 = -1;
float b0_32Hz_Etapa1 = 1;
float b1_32Hz_Etapa1 = -0.5346976901022821;
float b2_32Hz_Etapa1 = 0.13236825268212946;
float kA_32Hz_Etapa1 = 0.43381587365893526;

////////////////////////////////////

/**
 * Processing function
 */
bool dspSystem::process(float* in,float* out) {

  float* tmpIn = in;
  float aux[1024];
  float* tmp = aux;
  float* tmpOut = out;

///////////////////////////Aqui se arman los filtros//////////////////////////////////////////////

  //cv_->filter(bufferSize_,volumeGain_,tmpIn,/*tmp,*/tmpOut);
  cvA_->setCoefieciente(a0_32Hz_Etapa1, a1_32Hz_Etapa1, a2_32Hz_Etapa1, b0_32Hz_Etapa1, b1_32Hz_Etapa1, b2_32Hz_Etapa1, kA_32Hz_Etapa1);
  cvA_->filter(bufferSize_,volumeGain32Hz_,tmpIn,tmpOut);



/////////////////////////////////////////////////////////////////////////////////////////////////
  return true;
}

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
