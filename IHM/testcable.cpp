/******************************************************************************
* Nom du fichier : testcable.cpp
* Auteur : Rossetto-Giaccherino François
* Date de création : 27/02/24 (27 Fevrier 2024)
* Date de dernière modification : 29/03/24
* Description : testcable.cpp, fichier qui gere la fenetre principale TestCable. Classe de base du projet TestCable
******************************************************************************/

#include "testcable.h"
#include "ui_testcable.h"

int aide = 0; //Permet de detecter si la fenetre aide a ete ouverte
QString s;

TestCable::TestCable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestCable)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icone.ico"));
    readChip = new ReadChip(this);
    loadSettings();

    connect(readChip, &ReadChip::bloqueur, this, &TestCable::numDevsCheck);
    connect(ui->cboProg, &QComboBox::currentIndexChanged, this, &TestCable::cboProgIndexCheck);

    connect(ui->pbuScan, &QPushButton::clicked, this, &TestCable::scanAndPopulateDeviceInfo);
    model = new QStandardItemModel(this);
    ui->tbvDevices->setEditTriggers(QAbstractItemView::NoEditTriggers);
    readChip->populateDeviceInfo(model);
    ui->tbvDevices->setModel(model);
    ui->tbvDevices->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    fenetreAide = new Aide(nullptr);
    connect(ui->clblAide, SIGNAL(clicked()), this, SLOT(afficherAide()));
    connect(fenetreAide, &Aide::cboAideProgIndexChanged, this, &TestCable::updateCboProg);


    ui->dlneDateCode->generateDateCode();
    ui->dlneDateCode->setReadOnly(true);//(false) pour pouvoir editer le DateCode

    connect( ui->pbuDir, SIGNAL( clicked() ), this, SLOT( getDir() ) ) ;

    ui->txeConsole->setReadOnly(true);
    ui->txeConsole->setAcceptRichText(true);
    connect(readChip, &ReadChip::consoleOutput, this, &TestCable::appendToConsole);
}
TestCable::~TestCable()
{
    delete ui;
}

void TestCable::numDevsCheck(int value){
    qDebug() << "Valeur de numDevs :" << value;
    nombreChip = value;
    bloqueur();
}
void TestCable::cboProgIndexCheck(int value){
    qDebug() << "Valeur de index cboProg :" << value;
    index = value;
    bloqueur();
}
void TestCable::bloqueur(){

    if (nombreChip == 1 && index != 0) {
        ui->pbuProg->setEnabled(true);
    } else {
        ui->pbuProg->setEnabled(false);
    }
}

void TestCable::scanAndPopulateDeviceInfo()
{

    model->clear();
    readChip->populateDeviceInfo(model);
}

void TestCable::afficherAide() {
    aide++;
    fenetreAide->show();
}

void TestCable::updateCboProg(int index) {
    ui->cboProg->setCurrentIndex(index);
}

void TestCable::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);

    // Obtenez le chemin du label lblBdd
    QString databaseFilePath = ui->lblBdd->text();

    if (databaseFilePath == "Pas encore sélectionné") {
        // Si le chemin est vide, ouvrez le gestionnaire de fichiers
        getDir();
    } else {
        // Sinon, ouvrez directement la base de données avec le chemin existant
        setupDatabase(databaseFilePath);
    }
}

void TestCable::setupDatabase(const QString &databaseFilePath) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databaseFilePath+"/BDD.db");

    if (!db.open()) {
        qDebug() << "Erreur: Impossible d'ouvrir la base de données";
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Test");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'exécution de la requête SQL:" << model->lastError().text();
        return;
    }

    ui->tbvBdd->setModel(model);
    ui->tbvBdd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void TestCable::getDir() {
    QString cheminFichier = QFileDialog::getOpenFileName(this, "Chemin vers la BDD (.db) ...", QDir::homePath(), "Fichiers de base de données (*.db)");
    s = QFileInfo(cheminFichier).path();
    if (!s.isNull()) {
        ui->lblBdd->setText(s);
        setupDatabase(s);

    }
}

void TestCable::appendToConsole(const QString &text)
{
    ui->txeConsole->append(text);
}








void TestCable::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Sauvegarde", "Voulez vous envoyez une sauvegarde par mail ?",
                                  QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if (reply == QMessageBox::Yes) {
        event->accept();
    } else if (reply == QMessageBox::No) {
        event->accept();
    } else if (reply == QMessageBox::Cancel) {
        event->ignore();
    }
    if (aide != 0) {
        if (fenetreAide->isVisible()) {
            fenetreAide->close();
        }
    }

    saveSettings(s, ui->lneTesteur->text());

    // QSettings settings("LLFTestCable", "TestCable");
    // settings.clear();
    //pour "purger" les settings
}

void TestCable::loadSettings() {
    QSettings settings("LLFTestCable", "TestCable");
    QString databaseFilePath = settings.value("CheminBDD").toString();
    QString testeur = settings.value("ContenuTesteur", "EB").toString(); // Valeur par défaut : "EB"

    if (databaseFilePath.isEmpty()) {
        // C'est la première ouverture de l'application
        getDir();
    } else {
        // Utilisez le chemin enregistré
        ui->lblBdd->setText(databaseFilePath);
        setupDatabase(databaseFilePath);
        s = databaseFilePath;
    }
    ui->lneTesteur->setText(testeur);
}

void TestCable::saveSettings(const QString &databaseFilePath, const QString &testeur) {
    QSettings settings("LLFTestCable", "TestCable");
    settings.setValue("CheminBDD", databaseFilePath);
    settings.setValue("ContenuTesteur", testeur);
}
