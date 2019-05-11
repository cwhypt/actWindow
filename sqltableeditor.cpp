
#include <QtWidgets>
#include <QtSql>
#include <QModelIndex>

#include "sqltableeditor.h"

//! [0]
TableEditor::TableEditor(QWidget *parent)
    : QWidget(parent)
{
    model = new QSqlTableModel(this);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Value"));


    QTableView *view = new QTableView;
    view->setModel(model);
    //view->hideColumn(0); // don't show the ID
    //view->show();
    //int salary = model.record(4).value("salary").toInt();
    view->resizeColumnsToContents();

    addButton = new QPushButton(tr("Add"));
    deleteButton = new QPushButton(tr("Delete"));
    submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    revertButton = new QPushButton(tr("&Revert"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(addButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(deleteButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);


    connect(addButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(delete_()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));


    //QItemSelectionModel *currentIndex = view->selectionModel();
    //QModelIndexList selectedRows ( int column = 0 ) const

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Cached Table"));
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
    int numRow=model->rowCount();
    model->insertRows(numRow,1);
}
void TableEditor::delete_()
{

    QTableView *view = new QTableView;
    view->setModel(model);
    QAbstractItemModel * model = view->model();
    QItemSelectionModel *currentIndex = view->selectionModel();
    QModelIndexList currentRow=currentIndex->selectedRows();
    if (!currentRow.isEmpty()){
        QModelIndex indexRow=currentRow.at(0);
        int row=indexRow.row();
        if( row)
        {
        model->removeRows(row,1);
        }
    }
}

void TableEditor::close()
{
   QApplication::quit();
}



//! [5]
