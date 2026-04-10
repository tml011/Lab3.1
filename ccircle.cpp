#include "ccircle.h"

CCircle::CCircle(int x, int y): x(x), y(y) {}

void CCircle::draw(QPainter &painter){
    if (selected){
        painter.setPen(QPen(Qt::red, 3));
    } else{
        painter.setPen(QPen(Qt::black, 1));
    }

    painter.drawEllipse(QPoint(x, y), radius, radius);
}

bool CCircle::isHit(QPoint &pos){
    int dx = pos.x() - x;
    int dy = pos.y() - y;

    return (dx * dx + dy * dy) <= (radius * radius);
}
