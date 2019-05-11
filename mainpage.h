#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

#include "sqltableeditor.h"
#include "defaultvalue.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE

//! [0]
class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);


};
//! [0]

#endif

