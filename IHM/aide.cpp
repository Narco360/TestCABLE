#include "aide.h"
#include "ui_aide.h"

Aide::Aide(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Aide)
{
    ui->setupUi(this);

    setWindowTitle("Aide");
}

Aide::~Aide()
{
    delete ui;
}
