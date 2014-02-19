

#include <QApplication>
#include <QTextEdit>
#include "ui_test.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);

    Ui_MainWindow mainUI;
    QMainWindow *mainWindow = new QMainWindow();
    mainUI.setupUi(mainWindow);
    mainWindow->show();
    return app.exec();
}


