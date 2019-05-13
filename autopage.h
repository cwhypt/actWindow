#ifndef AUTOPAGE_H
#define AUTOPAGE_H

#include <QWidget>

#include "sqltableeditor.h"
#include "defaultvalue.h"
#include <QDialog>
#include <QList>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE

//! [0]
class AutoPage : public QWidget
{
    Q_OBJECT

public:
    explicit AutoPage(QWidget *parent = 0);
     QString name0[10];
     QString name10[10];
     QString name20[10];
     QString name30[10];

     QString value0[10];
     QString value10[10];
     QString value20[10];
     QString value30[10];

    QSqlTableModel *model1;
    QSqlTableModel *model2;
    QSqlTableModel *model3;
    QSqlTableModel *model4;

    QList<QPushButton *> buttonList;


//signals:
//    void clicked(const QString &text);

private:
     QVBoxLayout *formLayout;
     QPushButton *click1;
     //QLineEdit *edit1;
     QBoxLayout *hlayout;
     QBoxLayout *vlayout;
     QSignalMapper *signalMapper1;
     QSignalMapper *signalMapper2;
     QSignalMapper *signalMapper3;
     QSignalMapper *signalMapper4;
     QGroupBox *groupBox;

     QSpacerItem *spacer;
private slots:

     void exec1(const int);
     void exec2(const int);
     void exec3(const int);
     void exec4(const int);
};
//! [0]

#endif

