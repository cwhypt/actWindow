#include <QtWidgets>
#include <QtSql>
#include <QClipboard>
#include <QMainWindow>


#include "autopage.h"


AutoPage::AutoPage(QWidget *parent)
    : QWidget(parent)
{
    vlayout=new QVBoxLayout(this);  //竖向排列
    hlayout=new QHBoxLayout(); //横向排列，包括各groupbox

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
        hlayout->addWidget(groupBox);

//第二部分
        signalMapper2=new QSignalMapper(this);

        groupBox= new QGroupBox(tr("F2"),this); //科研
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
                    this, SLOT(exec2(int)));
            hlayout->addWidget(groupBox);

            //第三部分
            signalMapper3=new QSignalMapper(this);

            groupBox= new QGroupBox(tr("F3"),this);  //课内
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
                hlayout->addWidget(groupBox);

                //第四部分
                signalMapper4=new QSignalMapper(this);

                groupBox= new QGroupBox(tr("F4"),this); //其他
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


                    hlayout->addWidget(groupBox);


        vlayout->addLayout (hlayout);


        //下列窗口
            signalMapper5=new QSignalMapper(this);

            groupBox= new QGroupBox(tr("窗口"),this);
            hformLayout= new QHBoxLayout;

            model5 = new QSqlTableModel(this);
            model5->setTable("person");
            model5->setFilter("ID > 960 and ID < 971");

            if (model5->select()) {
                int iter=model5->rowCount();
                for (int i=0;i<iter;i++){
                    QSqlRecord record = model5->record(i);
                    value40[i] = record.value("value").toString();
                    name40[i] = record.value("name").toString();
                    qDebug() << "Value" << ": " << value40[i];
                    click1=new QPushButton(name40[i]);
                    hformLayout->addWidget(click1);

                    connect(click1, SIGNAL(clicked()), signalMapper5, SLOT(map()));
                    signalMapper5->setMapping(click1,i);
                }
            }

                hformLayout->addStretch(1);
                groupBox->setLayout(hformLayout);
                connect(signalMapper5, SIGNAL(mapped(int)),
                        this, SLOT(exec5(int)));
                vlayout->addWidget(groupBox);



        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        vlayout->addSpacerItem(spacer);


        setLayout(vlayout);

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

void AutoPage::exec5(int i){
    QSqlRecord record = model5->record(i);
    QString uid = record.value("ID").toString();
    value40[i] = record.value("value").toString();
    name40[i] = record.value("name").toString();
    qDebug() << "Value" << ": " << value40[i];
    QMainWindow *wd=new QMainWindow(0);
    QString tt="Case ";
    tt+=uid;
    wd->setWindowTitle(tt);
    wd->show();
}
