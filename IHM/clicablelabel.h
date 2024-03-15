#ifndef CLICABLELABEL_H
#define CLICABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class ClicableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClicableLabel(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CLICABLELABEL_H
