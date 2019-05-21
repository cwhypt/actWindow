
#include <QtWidgets>
#include <QtSql>
#include <QClipboard>

#include "defaultvalue.h"
#include "sqltableeditor.h"

//! [0]
DefaultValue::DefaultValue(QWidget *parent)
    : QWidget(parent)
{

    QString value0;
    model = new QSqlTableModel(this);
    model->setTable("person");
    model->setFilter("ID = 901");
    if (model->select()) {
            QSqlRecord record = model->record(0);
            value0 = record.value("name").toString();
            qDebug() << "Name" << ": " << value0;

    }
    valueP=value0;     //注意在if条件句中的定义P到括号外边也会析构！！！
    QClipboard *clipboard = QApplication::clipboard();

    clipboard->setText(value0);

    QLabel *itemLabel = new QLabel(tr("Value: "));
    QLineEdit *lineEdit=new QLineEdit(valueP);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(itemLabel, lineEdit);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(formLayout);
    //layout->addWidget(buttonBox);

    //设置搜索



    setLayout(layout);
    TableEditor *tbUpdate = parent->findChild<TableEditor *>();
    connect(tbUpdate,SIGNAL(updateTable()),this,SLOT(update0()));



}



void DefaultValue::update0()
{
    QString value0;

    model->setFilter("ID = 901");
    if (model->select()) {
        if (model->rowCount() == 1) {
            QSqlRecord record = model->record(0);
            value0 = record.value("value").toString();
            qDebug() << "Value" << ": " << value0;
        }
    }
    valueP=value0;     //注意在if条件句中的定义到括号外边也会析构！！！

    QLineEdit *tbUpdate = this->findChild<QLineEdit *>();
    tbUpdate->setText(valueP);

}


//! [5]

