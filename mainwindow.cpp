#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jack.h"
#include <string>
#include <iostream>
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
        ui->lineEdit->setText(*it);
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
void MainWindow::on_verticalSlider_valueChanged(int value){
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolume(value);
}


//////////////////////Sliders Filtros/////////////////////////////////////////

void MainWindow::on_verticalSlider_2_valueChanged(int value32Hz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeA(value32Hz);
}

void MainWindow::on_verticalSlider_3_valueChanged(int value64Hz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeB(value64Hz);
}

void MainWindow::on_verticalSlider_4_valueChanged(int value125Hz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeC(value125Hz);
}

void MainWindow::on_verticalSlider_5_valueChanged(int value250Hz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeD(value250Hz);
}

void MainWindow::on_verticalSlider_6_valueChanged(int value500Hz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeE(value500Hz);
}

void MainWindow::on_verticalSlider_7_valueChanged(int value1kHz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeF(value1kHz);
}

void MainWindow::on_verticalSlider_8_valueChanged(int value2kHz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeG(value2kHz);
}

void MainWindow::on_verticalSlider_9_valueChanged(int value4kHz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeH(value4kHz);
}

void MainWindow::on_verticalSlider_10_valueChanged(int value8kHz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeI(value8kHz);
}

void MainWindow::on_verticalSlider_11_valueChanged(int value16kHz)
{
    if (!dspChanged_){
        dspChanged_=true;
    }
    dsp_->updateVolumeJ(value16kHz);
}


///////////////////////////////////////////////////////////////////////////////

//Botones

void MainWindow::on_toolButton_clicked(){
selectedFiles_ =
    QFileDialog::getOpenFileNames(this,
                                 "Select one or more audio files to open",
                                 ui->lineEdit->text(),
                                 "WAV Files (*.wav)");

if (!selectedFiles_.empty()) {
  ui->lineEdit->setText(*selectedFiles_.begin());

  jack::stopFiles();
  QStringList::iterator it;
  for (it=selectedFiles_.begin();it!=selectedFiles_.end();++it) {
    std::string tmp(qPrintable(*it));
    jack::playAlso(tmp.c_str());
  }
}
}


void MainWindow::on_lineEdit_returnPressed() {
  jack::stopFiles();
  std::string tmp(qPrintable(ui->lineEdit->text()));
  if (!tmp.empty()) {
    jack::playAlso(tmp.c_str());
  }
}

///Valores Predefinidos     ///100/24=25/6=4.16666666
void MainWindow::on_pushButton_clicked()
{
    ui->verticalSlider_2->setValue(71);
    ui->verticalSlider_3->setValue(62);
    ui->verticalSlider_4->setValue(42);
    ui->verticalSlider_5->setValue(37);
    ui->verticalSlider_6->setValue(46);
    ui->verticalSlider_7->setValue(54);
    ui->verticalSlider_8->setValue(71);
    ui->verticalSlider_9->setValue(76);
    ui->verticalSlider_10->setValue(76);
    ui->verticalSlider_11->setValue(76);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->verticalSlider_2->setValue(50);
    ui->verticalSlider_3->setValue(50);
    ui->verticalSlider_4->setValue(50);
    ui->verticalSlider_5->setValue(50);
    ui->verticalSlider_6->setValue(50);
    ui->verticalSlider_7->setValue(50);
    ui->verticalSlider_8->setValue(33);
    ui->verticalSlider_9->setValue(33);
    ui->verticalSlider_10->setValue(33);
    ui->verticalSlider_11->setValue(25);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->verticalSlider_2->setValue(33);
    ui->verticalSlider_3->setValue(50);
    ui->verticalSlider_4->setValue(62);
    ui->verticalSlider_5->setValue(62);
    ui->verticalSlider_6->setValue(62);
    ui->verticalSlider_7->setValue(62);
    ui->verticalSlider_8->setValue(62);
    ui->verticalSlider_9->setValue(54);
    ui->verticalSlider_10->setValue(54);
    ui->verticalSlider_11->setValue(54);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->verticalSlider_2->setValue(46);
    ui->verticalSlider_3->setValue(54);
    ui->verticalSlider_4->setValue(58);
    ui->verticalSlider_5->setValue(58);
    ui->verticalSlider_6->setValue(54);
    ui->verticalSlider_7->setValue(46);
    ui->verticalSlider_8->setValue(46);
    ui->verticalSlider_9->setValue(46);
    ui->verticalSlider_10->setValue(46);
    ui->verticalSlider_11->setValue(46);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->verticalSlider_2->setValue(67);
    ui->verticalSlider_3->setValue(62);
    ui->verticalSlider_4->setValue(50);
    ui->verticalSlider_5->setValue(42);
    ui->verticalSlider_6->setValue(42);
    ui->verticalSlider_7->setValue(50);
    ui->verticalSlider_8->setValue(67);
    ui->verticalSlider_9->setValue(71);
    ui->verticalSlider_10->setValue(71);
    ui->verticalSlider_11->setValue(71);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->verticalSlider_2->setValue(58);
    ui->verticalSlider_3->setValue(54);
    ui->verticalSlider_4->setValue(46);
    ui->verticalSlider_5->setValue(46);
    ui->verticalSlider_6->setValue(50);
    ui->verticalSlider_7->setValue(54);
    ui->verticalSlider_8->setValue(62);
    ui->verticalSlider_9->setValue(67);
    ui->verticalSlider_10->setValue(67);
    ui->verticalSlider_11->setValue(75);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->verticalSlider_2->setValue(75);
    ui->verticalSlider_3->setValue(75);
    ui->verticalSlider_4->setValue(75);
    ui->verticalSlider_5->setValue(67);
    ui->verticalSlider_6->setValue(50);
    ui->verticalSlider_7->setValue(42);
    ui->verticalSlider_8->setValue(29);
    ui->verticalSlider_9->setValue(21);
    ui->verticalSlider_10->setValue(21);
    ui->verticalSlider_11->setValue(21);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->verticalSlider_2->setValue(21);
    ui->verticalSlider_3->setValue(21);
    ui->verticalSlider_4->setValue(21);
    ui->verticalSlider_5->setValue(42);
    ui->verticalSlider_6->setValue(54);
    ui->verticalSlider_7->setValue(75);
    ui->verticalSlider_8->setValue(99);
    ui->verticalSlider_9->setValue(99);
    ui->verticalSlider_10->setValue(99);
    ui->verticalSlider_11->setValue(99);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->verticalSlider_2->setValue(50);
    ui->verticalSlider_3->setValue(50);
    ui->verticalSlider_4->setValue(50);
    ui->verticalSlider_5->setValue(42);
    ui->verticalSlider_6->setValue(50);
    ui->verticalSlider_7->setValue(58);
    ui->verticalSlider_8->setValue(58);
    ui->verticalSlider_9->setValue(50);
    ui->verticalSlider_10->setValue(50);
    ui->verticalSlider_11->setValue(50);
}

/*
void MainWindow::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue();
}


void MainWindow::on_progressBar_2_valueChanged(int value)
{
    ui->progressBar_2->setValue();
}

void MainWindow::on_progressBar_3_valueChanged(int value)
{
    ui->progressBar_3->setValue();
}

void MainWindow::on_progressBar_4_valueChanged(int value)
{
    ui->progressBar_4->setValue();
}

void MainWindow::on_progressBar_5_valueChanged(int value)
{
    ui->progressBar_5->setValue();
}

void MainWindow::on_progressBar_6_valueChanged(int value)
{
    ui->progressBar_6->setValue();
}

void MainWindow::on_progressBar_7_valueChanged(int value)
{
    ui->progressBar_7->setValue();
}

void MainWindow::on_progressBar_8_valueChanged(int value)
{
    ui->progressBar_8->setValue();
}

void MainWindow::on_progressBar_9_valueChanged(int value)
{
    ui->progressBar_9->setValue();
}

void MainWindow::on_progressBar_10_valueChanged(int value)
{
    ui->progressBar_10->setValue();
}
*/
