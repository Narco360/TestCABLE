#include "readchip.h"

ReadChip::ReadChip(QObject *parent)
    : QObject{parent}
{

}
void ReadChip::populateDeviceInfo(QStandardItemModel *model)
{
    FT_STATUS ftStatus;
    FT_DEVICE_LIST_INFO_NODE *devInfo;
    DWORD numDevs;
    ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (ftStatus == FT_OK) {
        //qDebug() << "Number of devices is " << numDevs;
    }
    if (numDevs > 0) {
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


                model->appendRow(rowItems);
            }
        }
    }
    QStringList headers;
    headers << "Device :" << "Description :" << "Serial ID" << "ChipID" << "LocationID" /*<< "Type de Chip" << "flag"*/;
    model->setHorizontalHeaderLabels(headers);
}
