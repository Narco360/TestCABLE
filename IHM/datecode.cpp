/******************************************************************************
* Nom du fichier : datecode.cpp
* Auteur : Rossetto-Giaccherino François
* Description : datecode.cpp, Spécialisation de QLineEdit afficahant la date
* fichier personnel
******************************************************************************/

#include "datecode.h"

DateCode::DateCode(QWidget *parent) : QLineEdit(parent)
{
    setReadOnly(true); // Rendre le QLineEdit en lecture seule
    generateDateCode(); // Générer le DateCode lors de la création
}

void DateCode::generateDateCode()
{
    // Obtenir la date actuelle
    QDate currentDate = QDate::currentDate();

    // Formater la date pour obtenir jjMM
    QString dateCode = currentDate.toString("ddMM");

    // Définir le texte de l'objet DateCode dans l'interface utilisateur avec le date code généré
    setText(dateCode);
}
