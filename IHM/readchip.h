/******************************************************************************
* Nom du fichier : readchip.h
* Auteur : Rossetto-Giaccherino François
* Date de création : 08/03/24 (08 Mars 2024)
* Date de dernière modification : 29/03/24
* Description : En-Tete de readchip.cpp, fichier qui gere la lecture des Chips FTDI
******************************************************************************/

#ifndef READCHIP_H
#define READCHIP_H

#include <QObject>
#include <QStandardItemModel>
#include "ftd2xx.h"
#include <QDebug>

class ReadChip : public QObject // Assurez-vous que ReadChip hérite de QObject
{
    Q_OBJECT // Assurez-vous que vous avez cette macro pour utiliser les signaux et les slots

public:
    explicit ReadChip(QObject *parent = nullptr);
    void populateDeviceInfo(QStandardItemModel *model); // Assurez-vous que la signature de cette fonction est correcte
    DWORD numDevs;
    FT_HANDLE ftHandle;
signals:
    void consoleOutput(const QString &text);
    void bloqueur(int value);
};

#endif // READCHIP_H
