#ifndef MISSILE_H
#define MISSILE_H


#include <QGraphicsRectItem>
#include <QObject>


extern int globalVariable;

class missile: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    missile();
    static missile* getInstance();
signals:
    void scoreUpdated(int score);
public slots:
    void move();
private:
    static missile* instance;

};

#endif // BULLET_H

