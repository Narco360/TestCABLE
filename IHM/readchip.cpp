/******************************************************************************
* Nom du fichier : readchip.cpp
* Auteur : Rossetto-Giaccherino François
* Date de création : 08/03/24 (08 Mars 2024)
* Date de dernière modification : 29/03/24
* Description : readchip.cpp, fichier qui gere la lecture des Chips FTDI
******************************************************************************/
#include <QDebug>
#include "readchip.h"

ReadChip::ReadChip(QObject *parent)
    : QObject{parent}
{

}
void ReadChip::populateDeviceInfo(QStandardItemModel *model)
{
    DWORD numDevs;
    FT_STATUS ftStatus;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    FT_HANDLE ftHandle;


    ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (ftStatus == FT_OK){
        devInfo = (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);
        ftStatus = FT_GetDeviceInfoList(devInfo,&numDevs);
        if (ftStatus == FT_OK) {

            for (DWORD i = 0; i < numDevs; i++) {
                QList<QStandardItem *> rowItems;
                rowItems << new QStandardItem(QString::number(i + 1));                  //1. dev
                rowItems << new QStandardItem(devInfo[i].Description);                  //2. desc
                rowItems << new QStandardItem(devInfo[i].SerialNumber);                 //3. Serial
                rowItems << new QStandardItem(QString::number(devInfo[i].ID, 16));      //4. ChipID
                rowItems << new QStandardItem(QString::number(devInfo[i].LocId, 16));   //5. LocID
                //rowItems << new QStandardItem(QString::number(devInfo[i].Type, 16));    //6. Type
                //rowItems << new QStandardItem(QString::number(devInfo[i].Flags, 16));   //7. flag

                //AFFICHER DANS LE TABLEAU LE (devInfo[i].SerialNumber) des [i]Chips
                emit consoleOutput(devInfo[i].SerialNumber);
                model->appendRow(rowItems);

                ftStatus = FT_Open(i, &ftHandle);
                if (ftStatus == FT_OK){
                    qDebug() << ftHandle << devInfo[i].SerialNumber;
                }


            }

        }
    }
    qDebug() <<numDevs;
    if (numDevs < 1) {
        qDebug() << "emit bloqueur 0";
        emit consoleOutput("<font color='red'>Aucun Chip detecté</font>");
        emit bloqueur(0);
    }
    if (numDevs > 1){
        qDebug() << "emit bloqueur 0";
        emit consoleOutput("<font color='red'>N'utilisez pas plus d' 1 Chip à la fois</font>");
        emit bloqueur(0);
    }
    if (numDevs == 1) {
        qDebug() << "emit bloqueur 1";
        emit bloqueur(1);
    }

    QStringList headers;
    // Ces options sont ajoutables mais n'était pas presente dans l'application précédente -->
    headers << "Device :" << "Description :" << "Serial ID :" << "ChipID :" << "LocationID :" /*<< "Type de Chip" << "flag"*/;
    model->setHorizontalHeaderLabels(headers);
}
