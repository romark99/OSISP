#include "about.h"

#include <QMessageBox>

void showInfo() {
    QMessageBox msgBox;
    msgBox.setText("Калькулятор-конвертер для преобразования чисел из произвольных систем счисления в произвольные (можно ограничиться 16-ричной системой).\nМарковский Роман\n3 курс\nПО-1");
    msgBox.exec();
}
