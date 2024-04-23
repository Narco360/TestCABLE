/******************************************************************************
* Nom du fichier : progchip.cpp
* Auteur : Rossetto-Giaccherino François
* Date de création : 26/03/24 (26 Mars 2024)
* Date de dernière modification : 29/03/24
* Description : progchip.cpp, fichier qui gere la programmation des Chips FTDI
******************************************************************************/

#include "progchip.h"
#include <string.h>
#include <QDebug>


ProgChip::ProgChip() {}


bool ProgChip::ecrireInformationsFixes(FT_HANDLE ftHandle, const char* descriptionProduit) {
    FT_STATUS ftStatus;
    ftStatus = FT_Open(0, &ftHandle);
    if (ftStatus != FT_OK) {
        qDebug() << "Erreur lors de l'ouverture du périphérique FTDI.";
        return false;
    }

    FT_PROGRAM_DATA data;
    memset(&data, 0, sizeof(data));

    ftStatus = FT_EE_Read(ftHandle, &data);
    if (ftStatus != FT_OK) {
        qDebug() << "Erreur lors de la lecture des informations du chip EEPROM.";
        FT_Close(ftHandle);
        return false;
    }

    // Écrire le Manufacturer et ManufacturerId
    strncpy_s(data.Manufacturer, sizeof(data.Manufacturer), "EBConnections", _TRUNCATE);
    strncpy_s(data.ManufacturerId, sizeof(data.ManufacturerId), "EB", _TRUNCATE);

    // Écrire la Description du produit
    strncpy_s(data.Description, sizeof(data.Description), descriptionProduit, _TRUNCATE);

    ftStatus = FT_EE_Program(ftHandle, &data);
    if (ftStatus != FT_OK) {
        qDebug() << "Erreur lors de la programmation du chip avec les nouvelles informations.";
        FT_Close(ftHandle);
        return false;
    }

    FT_Close(ftHandle);
    qDebug() << "Nouvelles informations écrites avec succès sur le chip.";
    return true;
}
