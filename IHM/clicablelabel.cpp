#include "clicablelabel.h"

ClicableLabel::ClicableLabel(QWidget *parent) : QLabel(parent) {}

void ClicableLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    } else {
        QLabel::mousePressEvent(event);
    }
}
