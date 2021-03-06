#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <string>
#include <vector>
#include <QPushButton>
#include <QMessageBox>

using namespace std;

//void showInfo();
//bool whatBtn(int, int);
//string numToBaseStr(long long, int);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void appendToLabelFrom(string);
    void popFromLabelFrom();
    void clearLabelFrom();
    void changeSystemFrom(int);
    void changeSystemTo(int);
    void changedLabelText();
    void changeLabelTo();
    void setFromBase(int);
    int getFromBase();
    void setToBase(int);
    int getToBase();

public slots:
    void clickedButton0();
    void clickedButton1();
    void clickedButton2();
    void clickedButton3();
    void clickedButton4();
    void clickedButton5();
    void clickedButton6();
    void clickedButton7();
    void clickedButton8();
    void clickedButton9();
    void clickedButtonA();
    void clickedButtonB();
    void clickedButtonC();
    void clickedButtonD();
    void clickedButtonE();
    void clickedButtonF();
    void clickedButtonBack();
    void clickedButtonClear();
    void clickedButtonAbout();
    void changedComboBoxFrom(int);
    void changedComboBoxTo(int);

    void changedTimesNewRoman();
    void changedArial();
    void changedCalibri();
    void changedFont8();
    void changedFont12();
    void changedFont14();
    void changedNormal();
    void changedBold();
    void changedItalic();

signals:


protected:
    virtual void keyPressEvent(QKeyEvent *);

private:
    int fromBase;
    int toBase;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

