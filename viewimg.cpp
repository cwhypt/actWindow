
#include "imageitem.h"
#include "viewimg.h"
#include <QDebug>
//! [0]
View::View(int fileID, QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    setScene(scene);

    model = new QSqlTableModel(this);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->sort (0,Qt::AscendingOrder);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Value"));

    addItems(fileID);

    setMinimumSize(470, 370);



}
//! [1]

//! [3]
void View::addItems(int fileID)
{
    int imageOffset = 150;
    int leftMargin = 70;
    int topMargin = 40;

        ImageItem *image;   //绘图
        QGraphicsTextItem *label;
        QSqlRecord record = model->record(fileID);

        int id = record.value("id").toInt();

        QString fileLoc = record.value("name").toString();

        QString value = record.value("value").toString();


        int x =  leftMargin ;
        int y =  topMargin;

        QString filePath=".\\" +fileLoc;
        qDebug()<<filePath;

        image = new ImageItem(fileID, QPixmap(filePath));
        image->setData(0,0);
        image->setPos(x, y);
        scene->addItem(image);

        label = scene->addText(value);
        label->setDefaultTextColor(QColor("#d7d6d5"));
        QPointF labelOffset((120 - label->boundingRect().width()) / 2, 120.0);
        label->setPos(QPointF(x, y) + labelOffset);

}

void View::updateImage(int id, const QString &fileName)
{
    QList<QGraphicsItem *> items = scene->items();

    while(!items.empty()) {
        QGraphicsItem *item = items.takeFirst();

        if (ImageItem *image = qgraphicsitem_cast<ImageItem *>(item)) {
            if (image->id() == id){
                image->setPixmap(QPixmap("./" +fileName));
                image->adjust();
                break;
            }
        }
    }
}
//! [7]
