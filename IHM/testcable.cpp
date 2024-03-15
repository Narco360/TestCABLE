#include "testcable.h"
#include "ui_testcable.h"


TestCable::TestCable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestCable)
{
    ui->setupUi(this);

    //1. Choisir un programme dans cboProg débloquera pbuProg si on choisi une configuration
    debloquerProg(ui->cboProg, ui->pbuProg);

    //2. Appels depuis readchip.cpp, affiche les info dans tbvDevices
    connect(ui->pbuScan, &QPushButton::clicked, this, &TestCable::scanAndPopulateDeviceInfo);
    model = new QStandardItemModel(this);
    readChip = new ReadChip(this);
    readChip->populateDeviceInfo(model);
    ui->tbvDevices->setModel(model);
    ui->tbvDevices->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //3. Label "Choisir un programme ?" ouvre la fenetre Aide (avec les photos, pour identification du chip)
    connect(ui->clblAide, SIGNAL(clicked()), this, SLOT(afficherAide()));
}
TestCable::~TestCable()
{
    delete ui;
}

//1.1 Permet de detecter les changement de cboProg en continu
void TestCable::debloquerProg(QComboBox *unlocker,QPushButton *lock) // Lien "Changement dans la comboBox --> debloquage
{
    connect(unlocker, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TestCable::sltDebloquer);
    this->lock = lock;
}
//1.2 Definition du slot permettant de (de)bloquer pbuProg
void TestCable::sltDebloquer(int index)
{

    if ( index != 0) {
        lock->setEnabled(true);
    }else {
        lock->setEnabled(false);
    }
}

//2. (Re)affiche les informations dans le tableau (1ere execution a l'ouverture de l'app)
void TestCable::scanAndPopulateDeviceInfo()
{

    model->clear();
    readChip->populateDeviceInfo(model);
}

//3.
void TestCable::afficherAide() {
    Aide *fenetreAide = new Aide(nullptr);
    fenetreAide->show();
}

// Boite de dialogue lors de la fermeture de l'appli
void TestCable::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Sauvegarde", "Voulez vous envoyez une sauvegarde par mail ?",
                                  QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if (reply == QMessageBox::Yes) {
        event->accept();
    } else if (reply == QMessageBox::No) {
        event->accept();
    }else if (reply == QMessageBox::Cancel) {
        event->ignore();
    }
}
