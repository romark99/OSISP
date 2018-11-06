#include "helper.h"
#include "ui_helper.h"
#include <iostream>
#include <sstream>

Helper::Helper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Helper)
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
}

Helper::~Helper() {
    delete ui;
}

string Helper::numToBaseStr(long long n, int base) {
    const string chars = "0123456789ABCDEF";
    string str = "";
    if (n == 0)
        return "0";
    while (n > 0) {
        int digit = n % base;
        str = chars[digit] + str;
        n /= base;
    }
    return str;
}

void Helper::setFromBase(int n) {
    fromBase = n;
    ui->btn2->setEnabled(fromBase < 3 ? false : true);
    ui->btn3->setEnabled(fromBase < 4 ? false : true);
    ui->btn4->setEnabled(fromBase < 5 ? false : true);
    ui->btn5->setEnabled(fromBase < 5 ? false : true);
    ui->btn6->setEnabled(fromBase < 5 ? false : true);
    ui->btn7->setEnabled(fromBase < 5 ? false : true);
    ui->btn8->setEnabled(fromBase < 9 ? false : true);
    ui->btn9->setEnabled(fromBase < 9 ? false : true);
    ui->btnA->setEnabled(fromBase < 11 ? false : true);
    ui->btnB->setEnabled(fromBase < 11 ? false : true);
    ui->btnC->setEnabled(fromBase < 11 ? false : true);
    ui->btnD->setEnabled(fromBase < 11 ? false : true);
    ui->btnE->setEnabled(fromBase < 11 ? false : true);
    ui->btnF->setEnabled(fromBase < 11 ? false : true);
}

int Helper::getFromBase() {
    return fromBase;
}

void Helper::setToBase(int n) {
    toBase = n;
}

int Helper::getToBase() {
    return toBase;
}

void Helper::changeLabelTo() {
    bool ok;
    long long num = ui->lFrom->text().toLongLong(&ok, getFromBase());
    QString newStr = QString::fromStdString(numToBaseStr(num, getToBase()));
    ui->lTo->setText(newStr);
}

void Helper::changedLabelText() {
    changeLabelTo();
}

void Helper::appendToLabelFrom(string str) {
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

void Helper::popFromLabelFrom() {
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

void Helper::changedComboBoxFrom(int index) {
    int systems[6] = {2,3,4,8,10,16};
    int system = systems[index];
    setFromBase(system);
    ui->lFrom->setText("0");
    this->setFocus();
    emit changedLabelText();
}

void Helper::changedComboBoxTo(int index) {
    int systems[6] = {2,3,4,8,10,16};
    setToBase(systems[index]);
    this->setFocus();
    emit changedLabelText();
}

void Helper::clearLabelFrom() {
    ui->lFrom->setText("0");
    emit changedLabelText();
}

void Helper::clickedButton0() {
    appendToLabelFrom("0");
}

void Helper::clickedButton1() {
    appendToLabelFrom("1");
}

void Helper::clickedButton2() {
    appendToLabelFrom("2");
}

void Helper::clickedButton3() {
    appendToLabelFrom("3");
}

void Helper::clickedButton4() {
    appendToLabelFrom("4");
}

void Helper::clickedButton5() {
    appendToLabelFrom("5");
}

void Helper::clickedButton6() {
    appendToLabelFrom("6");
}

void Helper::clickedButton7() {
    appendToLabelFrom("7");
}

void Helper::clickedButton8() {
    appendToLabelFrom("8");
}

void Helper::clickedButton9() {
    appendToLabelFrom("9");
}

void Helper::clickedButtonA() {
    appendToLabelFrom("A");
}

void Helper::clickedButtonB() {
    appendToLabelFrom("B");
}

void Helper::clickedButtonC() {
    appendToLabelFrom("C");
}

void Helper::clickedButtonD() {
    appendToLabelFrom("D");
}

void Helper::clickedButtonE() {
    appendToLabelFrom("E");
}

void Helper::clickedButtonF() {
    appendToLabelFrom("F");
}

void Helper::clickedButtonBack() {
    popFromLabelFrom();
}

void Helper::clickedButtonClear() {
    clearLabelFrom();
}

void Helper::clickedButtonAbout() {
    showInfo();
}

void Helper::showInfo() {
    QMessageBox msgBox;
    msgBox.setText(" Калькулятор-конвертер для преобразования чисел из произвольных систем счисления в произвольные (можно ограничиться 16-ричной системой).");
    msgBox.exec();
}

void Helper::keyPressEvent(QKeyEvent* event) {
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
