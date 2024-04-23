/******************************************************************************
* Nom du fichier : aide.cpp
* Auteur : Rossetto-Giaccherino François
* Date de création : 15/03/24 (15 Mars 2024)
* Date de dernière modification : 29/03/24
* Description : aide.cpp, fichier qui gere la fenetre secondaire Aide
******************************************************************************/


#include "aide.h"
#include "ui_aide.h"

Aide::Aide(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Aide)
{
    ui->setupUi(this);

    setWindowTitle("Aide");
    setWindowIcon(QIcon(":/icone.ico"));

}

Aide::~Aide()
{
    delete ui;
}

void Aide::updateAideProgIndex(int index) {
    emit cboAideProgIndexChanged(index);
}
