#ifndef AIDE_H
#define AIDE_H

#include <QWidget>

namespace Ui {
class Aide;
}

class Aide : public QWidget
{
    Q_OBJECT

public:
    explicit Aide(QWidget *parent = nullptr);
    ~Aide();

private:
    Ui::Aide *ui;
};

#endif // AIDE_H
