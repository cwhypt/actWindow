
#include <QtWidgets>
#include <QtSql>
#include <QModelIndex>
#include <QDebug>
#include "dialogimg.h"
#include "sqltableeditor.h"

//! [0]
TableEditor::TableEditor(QWidget *parent)
    : QWidget(parent)
{
    model = new QSqlTableModel(this);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->sort (0,Qt::AscendingOrder);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Value"));
    model->setHeaderData(3, Qt::Horizontal, tr("Description"));


    view = new QTableView;
    view->setModel(model);
    //view->hideColumn(0); // don't show the ID
    //view->show();
    //int salary = model.record(4).value("salary").toInt();
    view->resizeColumnsToContents();

    addButton = new QPushButton(tr("Add"));
    deleteButton = new QPushButton(tr("Delete"));
    viewButton = new QPushButton(tr("View"));
    resetButton = new QPushButton(tr("Reset"));
    searchButton = new QPushButton(tr("Search"));
    submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    revertButton = new QPushButton(tr("&Revert"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(viewButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(addButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(deleteButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(resetButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);


    connect(addButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(delete_()));
    connect(viewButton, SIGNAL(clicked()), this, SLOT(viewImg()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchImg()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
    connect(resetButton, SIGNAL(clicked()), this, SLOT(reset_()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));


    currentModel = view->selectionModel();  //注意不能有重定义！否则覆盖

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout (mainLayout,1);

    QHBoxLayout *searchLayout = new QHBoxLayout;
    label1 = new QLabel(tr("Search1: "));
    edit1=new QLineEdit(this);
    searchLayout->addWidget (label1);
    searchLayout->addWidget (edit1);

    label2 = new QLabel(tr("Search2: "));
    edit2=new QLineEdit(this);
    searchLayout->addWidget (label2);
    searchLayout->addWidget (edit2);

    vlayout->addLayout (searchLayout);

    QHBoxLayout *formatLayout = new QHBoxLayout;
    anyButton=new QRadioButton("OR",this);
    allButton=new QRadioButton("AND",this);
    formatLayout->addWidget (anyButton);
    formatLayout->addWidget (allButton);
    formatLayout->addWidget(searchButton);
    formatLayout->addWidget(resetButton);

    vlayout->addLayout (formatLayout);

    setLayout(vlayout);
    connect(view->selectionModel(),SIGNAL(selectionChanged(const QItemSelection &,const QItemSelection &)),this,SLOT(selectedRow(const QItemSelection &,const QItemSelection &)));
    //一定注意 const不能省略！！（否则没有对应signal

}



void TableEditor::submit()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
        emit updateTable();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
}
void TableEditor::add()
{
    model->insertRows(currentRow,1);
}

void TableEditor::selectedRow(const QItemSelection &nowSelected, const QItemSelection &deslected){
   QModelIndexList selectedItem = nowSelected.indexes ();
   if (!selectedItem.empty()){
       QModelIndex selectedIndex = selectedItem[0];
        currentRow=selectedIndex.row();
   }
   qDebug() << "Selected" << ": " << currentRow;

}

void TableEditor::delete_()
{qDebug() << "Selected" << ": " << currentRow;

        model->removeRows(currentRow,1);

}

void TableEditor::close()
{
   QApplication::quit();
}


void TableEditor::viewImg()
{

    InformationWindow *infoWin=new InformationWindow(currentRow);
    infoWin->show ();

}

void TableEditor::searchImg()
{
    QSqlQuery query;
bool any=this->anyButton->isChecked ();
bool all=this->allButton->isChecked ();
QString crit1=this->edit1->text ();
QString crit2=this->edit2->text ();
QString arg1;

if(any){
    if(!crit1.isEmpty ())
        arg1+="Name = '"+crit1+"' OR ";
    if(!crit2.isEmpty ())
        arg1+="Value = '"+crit2+"' OR ";
    int len=arg1.length ();
    if(len){
        arg1.remove (len-4,4);
        qDebug()<<arg1;
        model->setFilter (arg1);
    }
  }
if(all){
    if(!crit1.isEmpty ())
        arg1+="Name = '"+crit1+"' AND ";
    if(!crit2.isEmpty ())
        arg1+="Value = '"+crit2+"' AND ";
    int len=arg1.length ();
    if(len){
        arg1.remove (len-5,5);
        qDebug()<<arg1;
        model->setFilter (arg1);
    }
  }
}
void TableEditor::reset_()
{
    model->setFilter (QString());
}



//! [5]
