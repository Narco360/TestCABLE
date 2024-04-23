/******************************************************************************
* Nom du fichier : datecode.h
* Auteur : Rossetto-Giaccherino François
* Description : En-tete du fichier clicablelabel.cpp, Spécialisation de QLabel
* fichier personnel
******************************************************************************/

#ifndef DATECODE_H
#define DATECODE_H

#include <QLineEdit>
#include <QDate>

class DateCode : public QLineEdit
{
    Q_OBJECT
public:
    explicit DateCode(QWidget *parent = nullptr);
    void generateDateCode();
private:

};

#endif // DATECODE_H
