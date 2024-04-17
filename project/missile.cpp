#include "missile.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>

missile* missile::instance = nullptr;

missile::missile() : QObject(), QGraphicsPixmapItem() {
   // setPixmap(QPixmap(":/missile.png")); // to set pic
   // setScale(0.5); // Adjust scale
}

missile* missile::getInstance() {
    if (instance == nullptr) {
        instance = new missile;
    }
    return instance;
}

void missile::move() {

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid((colliding_items[i])) == typeid(missile)){

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);


            delete colliding_items[i];
            delete this;

            //***increment score here***

            return;
        }
}
    setPos(x(),y()-10);
    if (pos().y() + boundingRect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}


