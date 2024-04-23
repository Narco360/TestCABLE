/******************************************************************************
* Nom du fichier : clicablelabel.h
* Auteur : Rossetto-Giaccherino François
* Description : En-tete du fichier clicablelabel.cpp, Spécialisation de QLabel
* fichier personnel
******************************************************************************/

#ifndef CLICABLELABEL_H
#define CLICABLELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEnterEvent> // Inclure QEnterEvent

class ClicableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClicableLabel(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override; // Utiliser QEnterEvent
    void leaveEvent(QEvent *event) override;
};

#endif // CLICABLELABEL_H
