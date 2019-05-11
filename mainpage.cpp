#include "mainpage.h"
#include <QtWidgets>
#include <QSizePolicy>


MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
{
    TableEditor *tableView=new TableEditor(this);
    {                                               //设定sizePolicy可伸展
    QSizePolicy sizeP=tableView->sizePolicy();
    sizeP.setVerticalPolicy(QSizePolicy::Expanding);
    tableView->setSizePolicy(sizeP);
    }
    DefaultValue *defaultValue=new DefaultValue(this);

    QFrame *line = new QFrame(this);
    line->setFrameShape(QFrame::HLine); // Horizontal line
    line->setFrameShadow(QFrame::Sunken);
    line->setLineWidth(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
                                          //设定sizePolicy可伸展
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);

    mainLayout->addWidget(defaultValue);
    mainLayout->addWidget(line);
    mainLayout->addWidget(tableView);
    setLayout(mainLayout);

}


