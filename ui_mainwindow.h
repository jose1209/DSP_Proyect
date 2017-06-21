/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *fileEdit;
    QToolButton *fileButton;
    QSlider *volumeSlider;
    QLabel *label;
    QTextBrowser *textBrowser;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Classical;
    QPushButton *Club;
    QPushButton *Dance;
    QPushButton *BandT;
    QPushButton *FullTreble;
    QPushButton *Pop;
    QPushButton *Reggae;
    QPushButton *Rock;
    QPushButton *Techno;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QSlider *volumef_1;
    QSlider *volumef_2;
    QSlider *volumef_3;
    QSlider *volumef_4;
    QSlider *volumef_5;
    QSlider *volumef_6;
    QSlider *volumef_7;
    QSlider *volumef_8;
    QSlider *volumef_9;
    QSlider *volumef_10;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *uno;
    QLabel *dos;
    QLabel *tres;
    QLabel *cuatro;
    QLabel *cinco;
    QLabel *seis;
    QLabel *siete;
    QLabel *ocho;
    QLabel *nueve;
    QLabel *diez;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 476);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 901, 74));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fileEdit = new QLineEdit(verticalLayoutWidget);
        fileEdit->setObjectName(QStringLiteral("fileEdit"));

        horizontalLayout->addWidget(fileEdit);

        fileButton = new QToolButton(verticalLayoutWidget);
        fileButton->setObjectName(QStringLiteral("fileButton"));

        horizontalLayout->addWidget(fileButton);


        verticalLayout->addLayout(horizontalLayout);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(130, 120, 21, 211));
        volumeSlider->setOrientation(Qt::Vertical);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 340, 67, 17));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(220, 0, 461, 31));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(680, 100, 82, 275));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Classical = new QPushButton(widget);
        Classical->setObjectName(QStringLiteral("Classical"));

        verticalLayout_2->addWidget(Classical);

        Club = new QPushButton(widget);
        Club->setObjectName(QStringLiteral("Club"));

        verticalLayout_2->addWidget(Club);

        Dance = new QPushButton(widget);
        Dance->setObjectName(QStringLiteral("Dance"));

        verticalLayout_2->addWidget(Dance);

        BandT = new QPushButton(widget);
        BandT->setObjectName(QStringLiteral("BandT"));

        verticalLayout_2->addWidget(BandT);

        FullTreble = new QPushButton(widget);
        FullTreble->setObjectName(QStringLiteral("FullTreble"));

        verticalLayout_2->addWidget(FullTreble);

        Pop = new QPushButton(widget);
        Pop->setObjectName(QStringLiteral("Pop"));

        verticalLayout_2->addWidget(Pop);

        Reggae = new QPushButton(widget);
        Reggae->setObjectName(QStringLiteral("Reggae"));

        verticalLayout_2->addWidget(Reggae);

        Rock = new QPushButton(widget);
        Rock->setObjectName(QStringLiteral("Rock"));

        verticalLayout_2->addWidget(Rock);

        Techno = new QPushButton(widget);
        Techno->setObjectName(QStringLiteral("Techno"));

        verticalLayout_2->addWidget(Techno);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(200, 100, 481, 271));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        volumef_1 = new QSlider(widget1);
        volumef_1->setObjectName(QStringLiteral("volumef_1"));
        volumef_1->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_1);

        volumef_2 = new QSlider(widget1);
        volumef_2->setObjectName(QStringLiteral("volumef_2"));
        volumef_2->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_2);

        volumef_3 = new QSlider(widget1);
        volumef_3->setObjectName(QStringLiteral("volumef_3"));
        volumef_3->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_3);

        volumef_4 = new QSlider(widget1);
        volumef_4->setObjectName(QStringLiteral("volumef_4"));
        volumef_4->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_4);

        volumef_5 = new QSlider(widget1);
        volumef_5->setObjectName(QStringLiteral("volumef_5"));
        volumef_5->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_5);

        volumef_6 = new QSlider(widget1);
        volumef_6->setObjectName(QStringLiteral("volumef_6"));
        volumef_6->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_6);

        volumef_7 = new QSlider(widget1);
        volumef_7->setObjectName(QStringLiteral("volumef_7"));
        volumef_7->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_7);

        volumef_8 = new QSlider(widget1);
        volumef_8->setObjectName(QStringLiteral("volumef_8"));
        volumef_8->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_8);

        volumef_9 = new QSlider(widget1);
        volumef_9->setObjectName(QStringLiteral("volumef_9"));
        volumef_9->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_9);

        volumef_10 = new QSlider(widget1);
        volumef_10->setObjectName(QStringLiteral("volumef_10"));
        volumef_10->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(volumef_10);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(220, 370, 461, 31));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        uno = new QLabel(widget2);
        uno->setObjectName(QStringLiteral("uno"));

        horizontalLayout_3->addWidget(uno);

        dos = new QLabel(widget2);
        dos->setObjectName(QStringLiteral("dos"));

        horizontalLayout_3->addWidget(dos);

        tres = new QLabel(widget2);
        tres->setObjectName(QStringLiteral("tres"));

        horizontalLayout_3->addWidget(tres);

        cuatro = new QLabel(widget2);
        cuatro->setObjectName(QStringLiteral("cuatro"));

        horizontalLayout_3->addWidget(cuatro);

        cinco = new QLabel(widget2);
        cinco->setObjectName(QStringLiteral("cinco"));

        horizontalLayout_3->addWidget(cinco);

        seis = new QLabel(widget2);
        seis->setObjectName(QStringLiteral("seis"));

        horizontalLayout_3->addWidget(seis);

        siete = new QLabel(widget2);
        siete->setObjectName(QStringLiteral("siete"));

        horizontalLayout_3->addWidget(siete);

        ocho = new QLabel(widget2);
        ocho->setObjectName(QStringLiteral("ocho"));

        horizontalLayout_3->addWidget(ocho);

        nueve = new QLabel(widget2);
        nueve->setObjectName(QStringLiteral("nueve"));

        horizontalLayout_3->addWidget(nueve);

        diez = new QLabel(widget2);
        diez->setObjectName(QStringLiteral("diez"));

        horizontalLayout_3->addWidget(diez);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        fileButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Volumen", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Proyecto Procesamiento Digital de Se\303\261ales. Carmona es un guapo.</p></body></html>", Q_NULLPTR));
        Classical->setText(QApplication::translate("MainWindow", "Classical", Q_NULLPTR));
        Club->setText(QApplication::translate("MainWindow", "Club", Q_NULLPTR));
        Dance->setText(QApplication::translate("MainWindow", "Dance", Q_NULLPTR));
        BandT->setText(QApplication::translate("MainWindow", "BandT", Q_NULLPTR));
        FullTreble->setText(QApplication::translate("MainWindow", "Full Treble", Q_NULLPTR));
        Pop->setText(QApplication::translate("MainWindow", "Pop", Q_NULLPTR));
        Reggae->setText(QApplication::translate("MainWindow", "Reggae", Q_NULLPTR));
        Rock->setText(QApplication::translate("MainWindow", "Rock", Q_NULLPTR));
        Techno->setText(QApplication::translate("MainWindow", "Techno", Q_NULLPTR));
        uno->setText(QApplication::translate("MainWindow", "31,5", Q_NULLPTR));
        dos->setText(QApplication::translate("MainWindow", "63", Q_NULLPTR));
        tres->setText(QApplication::translate("MainWindow", "125", Q_NULLPTR));
        cuatro->setText(QApplication::translate("MainWindow", "250", Q_NULLPTR));
        cinco->setText(QApplication::translate("MainWindow", "500", Q_NULLPTR));
        seis->setText(QApplication::translate("MainWindow", "1k", Q_NULLPTR));
        siete->setText(QApplication::translate("MainWindow", "2k", Q_NULLPTR));
        ocho->setText(QApplication::translate("MainWindow", "4k", Q_NULLPTR));
        nueve->setText(QApplication::translate("MainWindow", "8k", Q_NULLPTR));
        diez->setText(QApplication::translate("MainWindow", "16k", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
