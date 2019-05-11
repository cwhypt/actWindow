#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>

// table editor
#include "connection.h"
#include "sqltableeditor.h"
#include "defaultvalue.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dbReturn createDB=createConnection();
    if (createDB.ran)  //load database
        return 1;


    MainWindow w;
    w.show();


    return a.exec();

}

//cmd-> taskkill -IM Test.exe /F

//Qt生成：在Test中运行Qt for windows
//		cd C:\\Users\\cwh\\Documents\\build-Test-Desktop_Qt_5_4_1_MinGW_32bit-Release\\release\\
//		windeployqt Test.exe
