#ifndef TESTCABLE_H
#define TESTCABLE_H

#include <QComboBox>
#include <QPushButton>
#include <QWidget>
#include "readchip.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TestCable;
}
QT_END_NAMESPACE

class TestCable : public QWidget
{
    Q_OBJECT

public:
    TestCable(QWidget *parent = nullptr);
    ~TestCable();


private slots:
    void sltDebloquer(int index);

private:
    //1.
    void debloquerProg(QComboBox *unlocker, QPushButton *lock);
    Ui::TestCable *ui;
    QPushButton *lock; // Déclaration du bloc
    QComboBox *unlocker; // Déclaration de la "clé" pour le débloquer

    //2.
    void scanAndPopulateDeviceInfo();
    ReadChip *readChip;
    QStandardItemModel *model;

};
#endif // TESTCABLE_H
