/******************************************************************************
* Nom du fichier : progchip.h
* Auteur : Rossetto-Giaccherino François
* Date de création : 26/03/24 (26 Mars 2024)
* Date de dernière modification : 29/03/24
* Description : En-Tete de progchip.cpp, fichier qui gere la programmation des Chips FTDI
******************************************************************************/

#ifndef PROGCHIP_H
#define PROGCHIP_H

#include "ftd2xx.h"
#include "readchip.h"


class ProgChip
{
public:
    ProgChip();
    bool ecrireInformationsFixes(FT_HANDLE ftHandle, const char* descriptionProduit);
};

#endif // PROGCHIP_H
