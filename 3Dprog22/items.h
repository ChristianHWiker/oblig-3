#ifndef ITEMS_H
#define ITEMS_H
#include "visualobject.h"

class Items : public VisualObject
{
public:
    Items();
    ~Items() override;
    void init(GLint matrixUniform) override;
    void draw() override;
    bool collideWithItem();


};


/*class Items : public VisualObject
{
public:
    Items();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    qreal angle = 0;
    qreal speed = 0;
    qreal mouseEyeDirection = 0;
    QColor color;
}*/

#endif // ITEMS_H
