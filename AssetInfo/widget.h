#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "Database.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btnStore_clicked();

private:
    Ui::Widget *ui;

    Database *db;

    bool StoreItemInfo();
};

#endif // WIDGET_H
