#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExpValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int m_BotI, m_TopI;
    double m_BotD, m_TopD;

    QRegExpValidator *m_pValid;

public slots:
   void installMask();
   void showResult();

   void computeResult();

   void installPattern();
   void showRegResult();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
