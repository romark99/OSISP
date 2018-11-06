#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLibrary>
#include <QDebug>
#include <iostream>
#include <sstream>

//bool whatBtn(int fromBase, int n) {
//    return fromBase >= n;
//}

//string numToBaseStr(long long n, int base) {
//    const string chars = "0123456789ABCDEF";
//    string str = "";
//    if (n == 0)
//        return "0";
//    while (n > 0) {
//        int digit = n % base;
//        str = chars[digit] + str;
//        n /= base;
//    }
//    return str;
//}

//void showInfo() {
//    QMessageBox msgBox;
//    msgBox.setText("Калькулятор-конвертер для преобразования чисел из произвольных систем счисления в произвольные (можно ограничиться 16-ричной системой).\nМарковский Роман\n3 курс\nПО-1");
//    msgBox.exec();
//}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocus();

    setFromBase(10);
    setToBase(2);


    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(clickedButton0()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(clickedButton1()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(clickedButton2()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(clickedButton3()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(clickedButton4()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(clickedButton5()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(clickedButton6()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(clickedButton7()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(clickedButton8()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(clickedButton9()));
    connect(ui->btnA, SIGNAL(clicked()), this, SLOT(clickedButtonA()));
    connect(ui->btnB, SIGNAL(clicked()), this, SLOT(clickedButtonB()));
    connect(ui->btnC, SIGNAL(clicked()), this, SLOT(clickedButtonC()));
    connect(ui->btnD, SIGNAL(clicked()), this, SLOT(clickedButtonD()));
    connect(ui->btnE, SIGNAL(clicked()), this, SLOT(clickedButtonE()));
    connect(ui->btnF, SIGNAL(clicked()), this, SLOT(clickedButtonF()));
    connect(ui->btnBackspace, SIGNAL(clicked()), this, SLOT(clickedButtonBack()));
    connect(ui->btnClear, SIGNAL(clicked()), this, SLOT(clickedButtonClear()));
    connect(ui->btnAbout, SIGNAL(clicked()), this, SLOT(clickedButtonAbout()));

    connect(ui->cbFrom, SIGNAL(currentIndexChanged(int)), this, SLOT(changedComboBoxFrom(int)));
    connect(ui->cbTo, SIGNAL(currentIndexChanged(int)), this, SLOT(changedComboBoxTo(int)));

    connect(ui->actionTimes_New_Roman, SIGNAL(triggered()), this, SLOT(changedTimesNewRoman()));
    connect(ui->actionArial, SIGNAL(triggered()), this, SLOT(changedArial()));
    connect(ui->actionCalibri, SIGNAL(triggered()), this, SLOT(changedCalibri()));
    connect(ui->actionFont8, SIGNAL(triggered()), this, SLOT(changedFont8()));
    connect(ui->actionFont12, SIGNAL(triggered()), this, SLOT(changedFont12()));
    connect(ui->actionFont14, SIGNAL(triggered()), this, SLOT(changedFont14()));
    connect(ui->actionNormal, SIGNAL(triggered()), this, SLOT(changedNormal()));
    connect(ui->actionBold, SIGNAL(triggered()), this, SLOT(changedBold()));
    connect(ui->actionItalic, SIGNAL(triggered()), this, SLOT(changedItalic()));

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setFromBase(int n) {
    fromBase = n;

    QLibrary lib( "C:\\Users\\romark\\Dropbox\\OSISP\\project\\OSISP\\build-calculator-Desktop_Qt_5_11_1_MinGW_32bit-Debug\\debug\\helper_functions.dll");
    if( !lib.load() ) {
        qDebug() << "Loading failed!";
        return;
    }

    typedef bool ( *WhatBtn )( int, int );
    WhatBtn whatBtn = (WhatBtn) lib.resolve("whatBtn");
    if (whatBtn) {
        ui->btn2->setEnabled(whatBtn(fromBase, 3));
        ui->btn3->setEnabled(whatBtn(fromBase, 4));
        ui->btn4->setEnabled(whatBtn(fromBase, 5));
        ui->btn5->setEnabled(whatBtn(fromBase, 5));
        ui->btn6->setEnabled(whatBtn(fromBase, 5));
        ui->btn7->setEnabled(whatBtn(fromBase, 5));
        ui->btn8->setEnabled(whatBtn(fromBase, 9));
        ui->btn9->setEnabled(whatBtn(fromBase, 9));
        ui->btnA->setEnabled(whatBtn(fromBase, 11));
        ui->btnB->setEnabled(whatBtn(fromBase, 11));
        ui->btnC->setEnabled(whatBtn(fromBase, 11));
        ui->btnD->setEnabled(whatBtn(fromBase, 11));
        ui->btnE->setEnabled(whatBtn(fromBase, 11));
        ui->btnF->setEnabled(whatBtn(fromBase, 11));
    }
}

int MainWindow::getFromBase() {
    return fromBase;
}

void MainWindow::setToBase(int n) {
    toBase = n;
}

int MainWindow::getToBase() {
    return toBase;
}

void MainWindow::changeLabelTo() {
    bool ok;
    long long num = ui->lFrom->text().toLongLong(&ok, getFromBase());

    QLibrary lib( "C:\\Users\\romark\\Dropbox\\OSISP\\project\\OSISP\\build-calculator-Desktop_Qt_5_11_1_MinGW_32bit-Debug\\debug\\helper_functions.dll");
    if( !lib.load() ) {
        qDebug() << "Loading failed!";
        return;
    }

    typedef string ( *NumToBaseStr )( long long, int );
    NumToBaseStr numToBaseStr = (NumToBaseStr) lib.resolve("numToBaseStr");

    QString newStr = QString::fromStdString(numToBaseStr(num, getToBase()));
    ui->lTo->setText(newStr);
}

void MainWindow::changedLabelText() {
    changeLabelTo();
}

void MainWindow::appendToLabelFrom(string str) {
    QString qstr = QString::fromStdString(str);
    if (ui->lFrom->text() == "0") {
        if (str == "0")
            return;
        else {
            ui->lFrom->setText(qstr);
        }
    }
    else if (ui->lFrom->text().length() >= 15) {
        return;
    }
    else {
        ui->lFrom->setText(ui->lFrom->text() + qstr);
    }
    emit changedLabelText();
}

void MainWindow::popFromLabelFrom() {
    if (ui->lFrom->text().length() == 1) {
        ui->lFrom->setText("0");
    }
    else {
        QString str = ui->lFrom->text();
        str = str.left(str.length() - 1);
        ui->lFrom->setText(str);
    }
    emit changedLabelText();
}

void MainWindow::changedComboBoxFrom(int index) {
    int systems[6] = {2,3,4,8,10,16};
    int system = systems[index];
    setFromBase(system);
    ui->lFrom->setText("0");
    this->setFocus();
    emit changedLabelText();
}

void MainWindow::changedComboBoxTo(int index) {
    int systems[6] = {2,3,4,8,10,16};
    setToBase(systems[index]);
    this->setFocus();
    emit changedLabelText();
}

void MainWindow::clearLabelFrom() {
    ui->lFrom->setText("0");
    emit changedLabelText();
}

void MainWindow::clickedButton0() {
    appendToLabelFrom("0");
}

void MainWindow::clickedButton1() {
    appendToLabelFrom("1");
}

void MainWindow::clickedButton2() {
    appendToLabelFrom("2");
}

void MainWindow::clickedButton3() {
    appendToLabelFrom("3");
}

void MainWindow::clickedButton4() {
    appendToLabelFrom("4");
}

void MainWindow::clickedButton5() {
    appendToLabelFrom("5");
}

void MainWindow::clickedButton6() {
    appendToLabelFrom("6");
}

void MainWindow::clickedButton7() {
    appendToLabelFrom("7");
}

void MainWindow::clickedButton8() {
    appendToLabelFrom("8");
}

void MainWindow::clickedButton9() {
    appendToLabelFrom("9");
}

void MainWindow::clickedButtonA() {
    appendToLabelFrom("A");
}

void MainWindow::clickedButtonB() {
    appendToLabelFrom("B");
}

void MainWindow::clickedButtonC() {
    appendToLabelFrom("C");
}

void MainWindow::clickedButtonD() {
    appendToLabelFrom("D");
}

void MainWindow::clickedButtonE() {
    appendToLabelFrom("E");
}

void MainWindow::clickedButtonF() {
    appendToLabelFrom("F");
}

void MainWindow::clickedButtonBack() {
    popFromLabelFrom();
}

void MainWindow::clickedButtonClear() {
    clearLabelFrom();
}

void MainWindow::clickedButtonAbout() {

    QLibrary lib( "C:\\Users\\romark\\Dropbox\\OSISP\\project\\OSISP\\build-calculator-Desktop_Qt_5_11_1_MinGW_32bit-Debug\\debug\\about.dll");
    if( !lib.load() ) {
        qDebug() << "Loading failed!";
        return;
    }

    typedef void ( *ShowInfo )();
    ShowInfo showInfo = (ShowInfo) lib.resolve("showInfo");
    showInfo();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_0:
        emit ui->btn0->animateClick();
        break;
    case Qt::Key_1:
        emit ui->btn1->animateClick();
        break;
    case Qt::Key_2:
        emit ui->btn2->animateClick();
        break;
    case Qt::Key_3:
        emit ui->btn3->animateClick();
        break;
    case Qt::Key_4:
        emit ui->btn4->animateClick();
        break;
    case Qt::Key_5:
        emit ui->btn5->animateClick();
        break;
    case Qt::Key_6:
        emit ui->btn6->animateClick();
        break;
    case Qt::Key_7:
        emit ui->btn7->animateClick();
        break;
    case Qt::Key_8:
        emit ui->btn8->animateClick();
        break;
    case Qt::Key_9:
        emit ui->btn9->animateClick();
        break;
    case Qt::Key_A:
        emit ui->btnA->animateClick();
        break;
    case Qt::Key_B:
        emit ui->btnB->animateClick();
        break;
    case Qt::Key_C:
        emit ui->btnC->animateClick();
        break;
    case Qt::Key_D:
        emit ui->btnD->animateClick();
        break;
    case Qt::Key_E:
        emit ui->btnE->animateClick();
        break;
    case Qt::Key_F:
        emit ui->btnF->animateClick();
        break;
    case Qt::Key_Escape:
        emit ui->btnClear->animateClick();
        break;
    case Qt::Key_Backspace:
        emit ui->btnBackspace->animateClick();
        break;
    }
}

void MainWindow::changedTimesNewRoman() {
    QFont font = ui->centralWidget->font();
    font.setFamily("Times New Roman");
    ui->centralWidget->setFont(font);
}

void MainWindow::changedArial() {
    QFont font = ui->centralWidget->font();
    font.setFamily("Arial");
    ui->centralWidget->setFont(font);
}

void MainWindow::changedCalibri() {
    QFont font = ui->centralWidget->font();
    font.setFamily("Calibri");
    ui->centralWidget->setFont(font);
}

void MainWindow::changedFont8() {
    QFont font = ui->centralWidget->font();
    font.setPixelSize(8);
    ui->centralWidget->setFont(font);
}

void MainWindow::changedFont12() {
    QFont font = ui->centralWidget->font();
    font.setPixelSize(12);
    ui->centralWidget->setFont(font);
}

void MainWindow::changedFont14() {
    QFont font = ui->centralWidget->font();
    font.setPixelSize(14);
    ui->centralWidget->setFont(font);
}

void MainWindow::changedNormal() {
    QFont font = ui->centralWidget->font();
    font.setBold(false);
    font.setItalic(false);
    ui->centralWidget->setFont(font);
}

void MainWindow::changedBold() {
    QFont font = ui->centralWidget->font();
    font.setBold(true);
    font.setItalic(false);
    ui->centralWidget->setFont(font);
}

void MainWindow::changedItalic() {
    QFont font = ui->centralWidget->font();
    font.setBold(false);
    font.setItalic(true);
    ui->centralWidget->setFont(font);
}
