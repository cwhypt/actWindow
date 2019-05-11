#include <QtWidgets>
#include <QtSql>
#include <QClipboard>
#include <QMainWindow>


#include "autopage.h"


AutoPage::AutoPage(QWidget *parent)
    : QWidget(parent)
{
    layout=new QHBoxLayout(this);

//第一部分
    signalMapper1=new QSignalMapper(this);

    groupBox= new QGroupBox(tr("日常"),this);
    formLayout= new QVBoxLayout;

    model1 = new QSqlTableModel(this);
    model1->setTable("person");
    model1->setFilter("ID > 920 and ID < 931");

    if (model1->select()) {
        int iter=model1->rowCount();
        for (int i=0;i<iter;i++){
            QSqlRecord record = model1->record(i);
            value0[i] = record.value("value").toString();
            name0[i] = record.value("name").toString();
            qDebug() << "Value" << ": " << value0[i];
            click1=new QPushButton(name0[i]);
            formLayout->addWidget(click1);

            connect(click1, SIGNAL(clicked()), signalMapper1, SLOT(map()));
            signalMapper1->setMapping(click1,i);
        }
    }

        formLayout->addStretch(1);
        groupBox->setLayout(formLayout);
        connect(signalMapper1, SIGNAL(mapped(int)),
                this, SLOT(exec1(int)));
        layout->addWidget(groupBox);

//第二部分
        signalMapper2=new QSignalMapper(this);

        groupBox= new QGroupBox(tr("科研"),this);
        formLayout= new QVBoxLayout;

        model2 = new QSqlTableModel(this);
        model2->setTable("person");
        model2->setFilter("ID > 930 and ID < 941");

        if (model2->select()) {
            int iter=model2->rowCount();
            for (int i=0;i<iter;i++){
                QSqlRecord record = model2->record(i);
                value10[i] = record.value("value").toString();
                name10[i] = record.value("name").toString();
                qDebug() << "Value" << ": " << value10[i];
                click1=new QPushButton(name10[i]);
                formLayout->addWidget(click1);

                connect(click1, SIGNAL(clicked()), signalMapper2, SLOT(map()));
                signalMapper2->setMapping(click1,i);
            }
        }

            formLayout->addStretch(1);
            groupBox->setLayout(formLayout);
            connect(signalMapper2, SIGNAL(mapped(int)),
                    this, SLOT(exec1(int)));
            layout->addWidget(groupBox);

            //第三部分
            signalMapper3=new QSignalMapper(this);

            groupBox= new QGroupBox(tr("课内"),this);
            formLayout= new QVBoxLayout;

            model3 = new QSqlTableModel(this);
            model3->setTable("person");
            model3->setFilter("ID > 940 and ID < 951");

            if (model3->select()) {
                int iter=model3->rowCount();
                for (int i=0;i<iter;i++){
                    QSqlRecord record = model3->record(i);
                    value20[i] = record.value("value").toString();
                    name20[i] = record.value("name").toString();
                    qDebug() << "Value" << ": " << value20[i];
                    click1=new QPushButton(name20[i]);
                    formLayout->addWidget(click1);

                    connect(click1, SIGNAL(clicked()), signalMapper3, SLOT(map()));
                    signalMapper3->setMapping(click1,i);
                }
            }

                formLayout->addStretch(1);
                groupBox->setLayout(formLayout);
                connect(signalMapper3, SIGNAL(mapped(int)),
                        this, SLOT(exec3(int)));
                layout->addWidget(groupBox);

                //第四部分
                signalMapper4=new QSignalMapper(this);

                groupBox= new QGroupBox(tr("其他"),this);
                formLayout= new QVBoxLayout;

                model4 = new QSqlTableModel(this);
                model4->setTable("person");
                model4->setFilter("ID > 950 and ID < 961");

                if (model4->select()) {
                    int iter=model4->rowCount();
                    for (int i=0;i<iter;i++){
                        QSqlRecord record = model4->record(i);
                        value30[i] = record.value("value").toString();
                        name30[i] = record.value("name").toString();
                        qDebug() << "Value" << ": " << value30[i];
                        click1=new QPushButton(name30[i]);
                        formLayout->addWidget(click1);

                        connect(click1, SIGNAL(clicked()), signalMapper4, SLOT(map()));
                        signalMapper4->setMapping(click1,i);
                    }
                }

                    formLayout->addStretch(1);
                    groupBox->setLayout(formLayout);
                    connect(signalMapper4, SIGNAL(mapped(int)),
                            this, SLOT(exec4(int)));


        layout->addWidget(groupBox);
        //setLayout(layout);


}


void AutoPage::exec1(int i){

    QSqlRecord record = model1->record(i);
    QString uid = record.value("ID").toString();
    value0[i] = record.value("value").toString();
    name0[i] = record.value("name").toString();
    qDebug() << "Value" << ": " << value0[i];
    QMainWindow *wd=new QMainWindow(0);
    QString tt="Case ";
    tt+=uid;
    wd->setWindowTitle(tt);
    wd->show();
}

void AutoPage::exec2(int i){
    QSqlRecord record = model2->record(i);
    QString uid = record.value("ID").toString();
    value10[i] = record.value("value").toString();
    name10[i] = record.value("name").toString();
    qDebug() << "Value" << ": " << value10[i];
    QMainWindow *wd=new QMainWindow(0);
    QString tt="Case ";
    tt+=uid;
    wd->setWindowTitle(tt);
    wd->show();
}

void AutoPage::exec3(int i){
    QSqlRecord record = model3->record(i);
    QString uid = record.value("ID").toString();
    value20[i] = record.value("value").toString();
    name20[i] = record.value("name").toString();
    qDebug() << "Value" << ": " << value20[i];
    QMainWindow *wd=new QMainWindow(0);
    QString tt="Case ";
    tt+=uid;
    wd->setWindowTitle(tt);
    wd->show();
}

void AutoPage::exec4(int i){
    QSqlRecord record = model4->record(i);
    QString uid = record.value("ID").toString();
    value30[i] = record.value("value").toString();
    name30[i] = record.value("name").toString();
    qDebug() << "Value" << ": " << value30[i];
    QMainWindow *wd=new QMainWindow(0);
    QString tt="Case ";
    tt+=uid;
    wd->setWindowTitle(tt);
    wd->show();
}

