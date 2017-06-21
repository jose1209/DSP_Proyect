#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>
#include "dspsystem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int volumeGain;
    /**
      *Tolerance value
      */
    static const float Epsilon;

     /**
      * Verbose flag
      */
     bool verbose_;

     /**
      * Timer used to recompute the filter once the user changes the
      * values
      */
     QTimer *timer_;

     /**
      * List of selected files so far
      */
     QStringList selectedFiles_;

     /**
      * Pointer to an inherited class of processor, which does
      * all the real work.
      */
     dspSystem* dsp_;

     /**
      *DSP change
      */
     bool dspChanged_;

   private slots:
     void update();
     void on_toolButton_clicked();
     void on_lineEdit_returnPressed();
     /*


     void on_Classical_clicked();
     void on_Club_clicked();
     void on_volumef_1_valueChanged(int value32Hz);
     void on_Dance_clicked();
     void on_FullTreble_clicked();
     void on_BandT_clicked();
     void on_Pop_clicked();
     void on_Reggae_clicked();
     void on_Rock_clicked();
     void on_Techno_clicked();
*/
     void on_verticalSlider_valueChanged(int value);
     void on_verticalSlider_2_valueChanged(int value32Hz);
     void on_verticalSlider_3_valueChanged(int value64Hz);
     void on_verticalSlider_4_valueChanged(int value125Hz);
     void on_verticalSlider_5_valueChanged(int value250Hz);
     void on_verticalSlider_6_valueChanged(int value500Hz);
     void on_verticalSlider_7_valueChanged(int value1kHz);
     void on_verticalSlider_8_valueChanged(int value2kHz);
     void on_verticalSlider_9_valueChanged(int value4kHz);
     void on_verticalSlider_10_valueChanged(int value8kHz);
     void on_verticalSlider_11_valueChanged(int value16kHz);
     void on_pushButton_clicked();
     void on_pushButton_2_clicked();
     void on_pushButton_3_clicked();
     void on_pushButton_4_clicked();
     void on_pushButton_5_clicked();
     void on_pushButton_6_clicked();
     void on_pushButton_7_clicked();
     void on_pushButton_8_clicked();
     void on_pushButton_9_clicked();
     /*void on_progressBar_valueChanged(int value);
     void on_progressBar_2_valueChanged(int value);
     void on_progressBar_3_valueChanged(int value);
     void on_progressBar_4_valueChanged(int value);
     void on_progressBar_5_valueChanged(int value);
     void on_progressBar_6_valueChanged(int value);
     void on_progressBar_7_valueChanged(int value);
     void on_progressBar_8_valueChanged(int value);
     void on_progressBar_9_valueChanged(int value);
     void on_progressBar_10_valueChanged(int value);*/
};

#endif // MAINWINDOW_H
