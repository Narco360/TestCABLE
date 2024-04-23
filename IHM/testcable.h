/******************************************************************************
* Nom du fichier : testcable.h
* Auteur : Rossetto-Giaccherino François
* Date de création : 27/02/24 (27 Fevrier 2024)
* Date de dernière modification : 29/03/24
* Description : En-Tete de testcable.cpp, fichier qui gere la fenetre principale TestCable. Classe de base du projet TestCable
******************************************************************************/

#ifndef TESTCABLE_H
#define TESTCABLE_H

#include <QCloseEvent>
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>
#include <QWidget>
#include <QtSql>
#include <QFileDialog>
#include <QSettings>
#include <QDir>


#include "readchip.h"
#include "aide.h"
#include "datecode.h"

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

    int index;
    int nombreChip;
protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;

private:
    void saveSettings(const QString &databaseFilePath, const QString &testeur);
    void loadSettings();



    Ui::TestCable *ui;



    void scanAndPopulateDeviceInfo();
    ReadChip *readChip;
    QStandardItemModel *model;

    Aide *fenetreAide;


    void setupDatabase(const QString &databaseFilePath);


public slots:
    void updateCboProg(int index);
    void appendToConsole(const QString &text);
    void numDevsCheck(int value);
    void cboProgIndexCheck(int value);
private slots:

    void bloqueur();
    void afficherAide();
    void getDir();
};
#endif // TESTCABLE_H
