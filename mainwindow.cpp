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
 * \file   mainwindow.cpp
 *         Implements the equalizer H(w) computation
 * \author Pablo Alvarado
 * \date   2010.12.12
 *
 * $Id: equalizer.cpp $
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jack.h"
#include <string>
#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif

/**
 * Precision used by trimming
 */
const float MainWindow::Epsilon = 0.001;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    verbose_(false),
    dspChanged_(true)
{
    ui->setupUi(this);
    /*
     * Set up a timer 4 times in a second to check if the user
     * changed the equalizer values, and if so, then create a new
     * filter response
     */
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(250);

    dsp_ = new dspSystem;
    jack::init(dsp_);

    // parse some command line arguments
    QStringList argv(QCoreApplication::arguments());

    QStringList::const_iterator it(argv.begin());
    while(it!=argv.end()) {
      if ((*it)=="-v" || (*it)=="--verbose") {
        verbose_=true;
      } else if ((*it).indexOf(".wav",0,Qt::CaseInsensitive)>0) {
        ui->fileEdit->setText(*it);
        std::string tmp(qPrintable(*it));
        jack::playAlso(tmp.c_str());
      }
      ++it;
    }
}

MainWindow::~MainWindow() {
    jack::close();
    delete timer_;
    delete ui;
    delete dsp_;
}

void MainWindow::update() {
    if(dspChanged_){
        _debug("Updating" << std::endl);
        dspChanged_=false;
    }
}

//Slider del Volumen General

void MainWindow::on_volumeSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolume(value);
}

//////////////////////Sliders Filtros/////////////////////////////////////////

void MainWindow::on_volumef_1_valueChanged(int value32Hz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeA(value32Hz);
}

void MainWindow::on_volumef_2_valueChanged(int value64Hz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeB(value64Hz);
}

void MainWindow::on_volumef_3_valueChanged(int value125Hz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeC(value125Hz);

}

void MainWindow::on_volumef_4_valueChanged(int value250Hz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeD(value250Hz);

}

void MainWindow::on_volumef_5_valueChanged(int value500Hz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeE(value500Hz);

}

void MainWindow::on_volumef_6_valueChanged(int value1kHz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeF(value1kHz);

}

void MainWindow::on_volumef_7_valueChanged(int value2kHz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeG(value2kHz);

}

void MainWindow::on_volumef_8_valueChanged(int value4kHz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeH(value4kHz);

}

void MainWindow::on_volumef_9_valueChanged(int value8kHz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeI(value8kHz);

}

void MainWindow::on_volumef_10_valueChanged(int value16kHz){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeJ(value16kHz);

}

///////////////////////////////////////////////////////////////////////////////

//Botones
void MainWindow::on_fileButton_clicked() {
  selectedFiles_ =
      QFileDialog::getOpenFileNames(this,
                                   "Select one or more audio files to open",
                                   ui->fileEdit->text(),
                                   "WAV Files (*.wav)");

  if (!selectedFiles_.empty()) {
    ui->fileEdit->setText(*selectedFiles_.begin());

    jack::stopFiles();
    QStringList::iterator it;
    for (it=selectedFiles_.begin();it!=selectedFiles_.end();++it) {
      std::string tmp(qPrintable(*it));
      jack::playAlso(tmp.c_str());
    }
  }
}

void MainWindow::on_fileEdit_returnPressed() {
  jack::stopFiles();
  std::string tmp(qPrintable(ui->fileEdit->text()));
  if (!tmp.empty()) {
    jack::playAlso(tmp.c_str());
  }
}

//Valores Predefinidos

void MainWindow::on_Classical_clicked() {
    ui->volumef_1->setValue(10);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(60);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(50);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(80);
    ui->volumef_9->setValue(60);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_Club_clicked() {
    ui->volumef_1->setValue(10);
    ui->volumef_2->setValue(50);
    ui->volumef_3->setValue(30);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(50);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(50);
    ui->volumef_9->setValue(90);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_Dance_clicked() {
    ui->volumef_1->setValue(20);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(30);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(50);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(80);
    ui->volumef_9->setValue(20);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_BandT_clicked() {
    ui->volumef_1->setValue(10);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(90);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(90);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(80);
    ui->volumef_9->setValue(90);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_FullTreble_clicked() {
    ui->volumef_1->setValue(10);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(30);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(10);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(10);
    ui->volumef_9->setValue(90);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_Pop_clicked() {
    ui->volumef_1->setValue(30);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(30);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(30);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(30);
    ui->volumef_9->setValue(90);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_Reggae_clicked() {
    ui->volumef_1->setValue(40);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(30);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(40);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(80);
    ui->volumef_9->setValue(40);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_Rock_clicked() {
    ui->volumef_1->setValue(60);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(60);
    ui->volumef_4->setValue(40);
    ui->volumef_5->setValue(50);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(80);
    ui->volumef_9->setValue(60);
    ui->volumef_10->setValue(50);
}

void MainWindow::on_Techno_clicked() {
    ui->volumef_1->setValue(70);
    ui->volumef_2->setValue(20);
    ui->volumef_3->setValue(30);
    ui->volumef_4->setValue(70);
    ui->volumef_5->setValue(50);
    ui->volumef_6->setValue(60);
    ui->volumef_7->setValue(70);
    ui->volumef_8->setValue(80);
    ui->volumef_9->setValue(70);
    ui->volumef_10->setValue(50);
}










