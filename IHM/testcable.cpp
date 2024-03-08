#include "testcable.h"
#include "ui_testcable.h"


TestCable::TestCable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestCable)
{
    ui->setupUi(this);


    connect(ui->pbuScan, &QPushButton::clicked, this, &TestCable::scanAndPopulateDeviceInfo);
    debloquerProg(ui->cboProg, ui->pbuProg); //1.

    //2. Appel depuis readchip.cpp, affiche les info dans tbvDevices
    model = new QStandardItemModel(this);
    readChip = new ReadChip(this);
    readChip->populateDeviceInfo(model);
    ui->tbvDevices->setModel(model);
    ui->tbvDevices->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
TestCable::~TestCable()
{
    delete ui;
}

//1.  Choisir un programme dans cboProg débloquera pbuProg si on choisi une configuration
void TestCable::debloquerProg(QComboBox *unlocker,QPushButton *lock) // Lien "Changement dans la comboBox --> debloquage
{
    connect(unlocker, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TestCable::sltDebloquer);
    this->lock = lock;
}
void TestCable::sltDebloquer(int index) //  Slot artisanal (existe dans d'autres versions de QT. Impossible de lier depuis Designer)
{

    if ( index != 0) {
        lock->setEnabled(true);
    }else {
        lock->setEnabled(false);
    }
}

//2.
void TestCable::scanAndPopulateDeviceInfo()
{
    // Effacer les données précédentes du tableau
    model->clear();

    // Appeler la fonction pour scanner et afficher les informations du chip
    readChip->populateDeviceInfo(model);
}
