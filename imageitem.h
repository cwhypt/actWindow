
#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QtCore>
#include <QtWidgets/QGraphicsPixmapItem>

//! [0]
class ImageItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ImageItem(int id, const QPixmap &pixmap, QGraphicsItem *parent = 0);

    void adjust();
    int id();

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) Q_DECL_OVERRIDE;

private slots:
    void setFrame(int frame);
    void updateItemPosition();

private:
    QTimeLine timeLine;
    int recordId;
    double z;
};
//! [0]

#endif
