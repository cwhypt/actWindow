#ifndef INFORMATIONWINDOW_H
#define INFORMATIONWINDOW_H

#include <QtWidgets>
#include <QtSql>
#include <QDialog>
#include "viewimg.h"
//! [0]
class InformationWindow : public QDialog
{
    Q_OBJECT

public:
    InformationWindow(int id,QWidget *parent = 0);

    int id();
    QSqlTableModel *model;

//! [1]
private slots:
    void revert();
    void submit();
    void enableButtons(bool enable = true);
//! [1]

//! [2]
private:
    void createButtons();

    int itemId;

    QLabel *itemText;
    QTextEdit *descriptionEditor;

    QPushButton *closeButton;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QDialogButtonBox *buttonBox;

    QDataWidgetMapper *mapper;
};
//! [2]

#endif
