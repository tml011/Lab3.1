#ifndef CCIRCLE_H
#define CCIRCLE_H
#include <QPainter>
#include <QPoint>

class CCircle
{
private:
    int x, y;
    int radius = 30;
    bool selected = false;

public:
    CCircle(int x, int y);

    void draw(QPainter &painter);
    bool isHit(const QPoint &pos);
    void setSelected(bool s){selected = s;}
    bool isSelected()const{return selected;}
};

#endif // CCIRCLE_H
