/******************************************************************************
* Nom du fichier : clicablelabel.cpp
* Auteur : Rossetto-Giaccherino François
* Description : clicablelabel.cpp, Spécialisation de QLabel le rendant cliquable (pour signal)
* fichier personnel
******************************************************************************/

#include "clicablelabel.h"

ClicableLabel::ClicableLabel(QWidget *parent) : QLabel(parent) {}

void ClicableLabel::mousePressEvent(QMouseEvent *event)//quand clic dessus
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    } else {
        QLabel::mousePressEvent(event);
    }
}

void ClicableLabel::enterEvent(QEnterEvent *event)//quand souris dessus
{
    QLabel::enterEvent(event);
    setStyleSheet("text-decoration: underline;"); //souligne
}

void ClicableLabel::leaveEvent(QEvent *event)//quand souris pas dessus
{
    QLabel::leaveEvent(event);
    setStyleSheet(""); // souligne plus
}
