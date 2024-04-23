/******************************************************************************
* Nom du fichier : aide.h
* Auteur : Rossetto-Giaccherino François
* Date de création : 15/03/24 (15 Mars 2024)
* Date de dernière modification : 29/03/24
* Description : En-Tete de aide.cpp, fichier qui gere la fenetre secondaire Aide
******************************************************************************/

#ifndef AIDE_H
#define AIDE_H

#include <QWidget>

namespace Ui {
class Aide;
}

class Aide : public QWidget
{
    Q_OBJECT

public:
    explicit Aide(QWidget *parent = nullptr);
    ~Aide();

private:
    Ui::Aide *ui;
signals:
    void cboAideProgIndexChanged(int index);
private slots:
    void updateAideProgIndex(int index);
};

#endif // AIDE_H
