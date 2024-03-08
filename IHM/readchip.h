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

signals:

};

#endif // READCHIP_H
