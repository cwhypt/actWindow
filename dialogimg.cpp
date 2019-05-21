#include <QtWidgets>
#include <QtSql>
#include "dialogimg.h"
#include <QSqlTableModel>
#include "viewimg.h"
//! [0]
//! [0]
InformationWindow::InformationWindow(int id,  QWidget *parent)  //注意此处不能换行
    : QDialog(parent)
{

    model = new QSqlTableModel(this);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->sort (0,Qt::AscendingOrder);
    model->select();

    QLabel *itemLabel = new QLabel(tr("Name: "));
    QLabel *descriptionLabel = new QLabel(tr("Value: "));

    createButtons();

    itemText = new QLabel;
    descriptionEditor = new QTextEdit;
//! [1]

//! [3]
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->addMapping(itemText, 1, "text");
    mapper->addMapping(descriptionEditor, 3);
    mapper->setCurrentIndex(id);
//! [3]

//! [4]
    connect(descriptionEditor, SIGNAL(textChanged()),
            this, SLOT(enableButtons()));


    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(itemLabel, itemText);

    formLayout->addRow(descriptionLabel, descriptionEditor);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(formLayout);
    layout->addWidget(buttonBox);


    View *viewWin=new View(id); //注意不能不加*：禁止copy
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget (viewWin,1);

    hlayout->addLayout (layout,0);

    setLayout(hlayout);

    itemId = id;

    setWindowFlags(Qt::Window);
    enableButtons(false);
    setWindowTitle(itemText->text());
}
//! [4]

//! [5]
int InformationWindow::id()
{
    return itemId;
}
//! [5]

//! [6]
void InformationWindow::revert()
{
    mapper->revert();
    enableButtons(false);
}
//! [6]

//! [7]
void InformationWindow::submit()
{
    mapper->submit();
    mapper->setCurrentIndex(itemId);

    enableButtons(false);
}
//! [7]

//! [8]
void InformationWindow::createButtons()
{
    closeButton = new QPushButton(tr("&Close"));
    revertButton = new QPushButton(tr("&Revert"));
    submitButton = new QPushButton(tr("&Submit"));

    closeButton->setDefault(true);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(revertButton, SIGNAL(clicked()), this, SLOT(revert()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
//! [8]

//! [9]
    buttonBox = new QDialogButtonBox(this);
    buttonBox->addButton(submitButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ResetRole);
    buttonBox->addButton(closeButton, QDialogButtonBox::RejectRole);
}
//! [9]

//! [10]
void InformationWindow::enableButtons(bool enable)
{
    revertButton->setEnabled(enable);
    submitButton->setEnabled(enable);
}
//! [10]
