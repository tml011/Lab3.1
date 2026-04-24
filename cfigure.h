#ifndef CFIGURE_H
#define CFIGURE_H

#include <QPainter>
#include <QPoint>
#include <QColor>
#include <QRect>

enum FigureType { TYPE_CIRCLE, TYPE_SQUARE };

class CFigure {
protected:
    int x, y;
    int w, h;
    bool selected = false;
    QColor color = Qt::black;
    FigureType type;

public:
    CFigure(int x, int y, int w, int h, FigureType t)
        : x(x), y(y), w(w), h(h), type(t) {}

    ~CFigure() {}

    void setSelected(bool s) { selected = s; }
    bool isSelected() const { return selected; }
    void setColor(const QColor &c) { color = c; }

    void draw(QPainter &painter) {
        if (selected) painter.setPen(QPen(Qt::red, 3));
        else painter.setPen(QPen(color, 2));

        switch (type) {
        case TYPE_CIRCLE:
            painter.drawEllipse(x - w/2, y - h/2, w, h);
            break;
        case TYPE_SQUARE:
            painter.drawRect(x - w/2, y - h/2, w, h);
            break;
        }
    }

    bool isHit(const QPoint &pos) {
        switch (type) {
        case TYPE_CIRCLE: {
            int dx = pos.x() - x;
            int dy = pos.y() - y;
            return (dx * dx + dy * dy) <= (w/2 * w/2);
        }
        case TYPE_SQUARE: {
            return QRect(x - w/2, y - h/2, w, h).contains(pos);
        }
        }
        return false;
    }

    bool canMoveTo(int nextX, int nextY, int canvasW, int canvasH) {
        int left = nextX - w/2;
        int top = nextY - h/2;
        int right = nextX + w/2;
        int bottom = nextY + h/2;

        return (left >= 0 && top >= 0 && right <= canvasW && bottom <= canvasH);
    }

    void move(int dx, int dy, int canvasW, int canvasH) {
        if (canMoveTo(x + dx, y + dy, canvasW, canvasH)) {
            x += dx;
            y += dy;
        }
    }
};

#endif