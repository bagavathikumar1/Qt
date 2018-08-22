#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->txtMask, SIGNAL(returnPressed()), this, SLOT(installMask()));
    connect(ui->txtInput, SIGNAL(returnPressed()), this, SLOT(showResult()));

    connect(ui->txtMask, SIGNAL(textChanged(QString)), this, SLOT(installMask()));
    connect(ui->txtInput, SIGNAL(textChanged(QString)), this, SLOT(showResult()));

    m_BotI = 5;
    m_TopI = 9;
    m_BotD = 99.9;
    m_TopD = 149.9;

    QIntValidator* iValid(new QIntValidator(m_BotI, m_TopI, this));
    QDoubleValidator* dValid(new QDoubleValidator(m_BotD, m_TopD, 2, this));
    ui->txtWork->setValidator(iValid);
    ui->txtPay->setValidator(dValid);

    connect(ui->txtWork, SIGNAL(returnPressed()), this, SLOT(computeResult()));
    connect(ui->txtPay, SIGNAL(returnPressed()), this, SLOT(computeResult()));


    m_pValid = new QRegExpValidator(this);

    connect(ui->txtPattern, SIGNAL(returnPressed()), this, SLOT(installPattern()));
    connect(ui->txtRegInput, SIGNAL(returnPressed()), this, SLOT(showRegResult()));

    connect(ui->txtPattern, SIGNAL(textChanged(QString)), this, SLOT(installPattern()));
    connect(ui->txtRegInput, SIGNAL(textChanged(QString)), this, SLOT(showRegResult()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::installMask() {
   ui->txtInput->setInputMask(ui->txtMask->text());
}

void MainWindow::showResult() {
    QString str = ui->txtInput->text();
    ui->txtResult->setText(str);
}


void MainWindow::computeResult() {

    double d = ui->txtPay->text().toDouble();
    int i = ui->txtWork->text().toInt();
    double res = d * i;
    ui->txtTotal->setText(QString("%1").arg(res));
}

void MainWindow::installPattern() {
    QRegExp rx(ui->txtPattern->text());
    m_pValid->setRegExp(rx);
    ui->txtRegInput->setValidator(m_pValid);
}

void MainWindow::showRegResult() {

    QString str = ui->txtRegInput->text();
    ui->txtRegResult->setText(str);
}
