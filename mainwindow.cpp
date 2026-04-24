#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for(int i = 0; i < storage.getCount(); i++){
        storage.getObject(i)->draw(painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        bool hitFound = false;

        for (int i = storage.getCount() - 1; i >= 0; --i) {
            CCircle* obj = storage.getObject(i);

            if (obj->isHit(event->pos())) {
                hitFound = true;

                if (!(event->modifiers() & Qt::ControlModifier)) {
                    for (int j = 0; j < storage.getCount(); ++j) {
                        storage.getObject(j)->setSelected(false);
                    }
                }

                obj->setSelected(true);

            }
        }

        if (!hitFound) {
            if (!(event->modifiers() & Qt::ControlModifier)) {
                for (int j = 0; j < storage.getCount(); ++j) {
                    storage.getObject(j)->setSelected(false);
                }
            }
            storage.add(new CCircle(event->pos().x(), event->pos().y()));
        }

        update();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        storage.deleteSelected();
        update();
    }
}
