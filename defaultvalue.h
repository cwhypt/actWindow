
#ifndef DEFAULTVALUE_H
#define DEFAULTVALUE_H

#include <QtWidgets>
#include <QDialog>
#include <qsqltablemodel.h>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QPushButton;
class QSqlTableModel;
QT_END_NAMESPACE

//! [0]
class DefaultValue : public QWidget
{
    Q_OBJECT

public:
    explicit DefaultValue(QWidget *parent = 0);

    QSqlTableModel *model;



private slots:
    void update0();

private:
    QString valueP;

};
//! [0]

#endif
