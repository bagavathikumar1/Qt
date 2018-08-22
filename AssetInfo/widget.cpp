#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = new Database;

    QSqlQuery query;
    //QString strRow = ui.lstCustomer->item(nRow)->text() ;
    QString strQuery = "SELECT * FROM asset";
    if(!query.exec(strQuery))
        qDebug() << "Error running query:" << strQuery;

    query.next() ;
    ui->txtItem->setText(query.value(2).toString());
    /*ui.txtCustName->setText() ;
    ui.txtCustAddress->setText(query.value(2).toString()) ;
    ui.txtContactPerson->setText(query.value(3).toString()) ;
    ui.txtCustPhone->setText(query.value(4).toString()) ;
    ui.txtMobile->setText(query.value(5).toString()) ;
    ui.txtCustMaxDebt->setText(query.value(6).toString()) ;*/
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::StoreItemInfo()
{
    QString strItem = ui->txtItem->text() ;
    QString strDesc = ui->txtDesc->toPlainText() ;
    QString strCatagory = ui->cmbCatagory->currentText() ;
    QString strPartNo = ui->txtPartNo->text();
    QString strManufacturer = ui->txtManufacturer->text();

    qDebug() << "Running query" ;
    QSqlQuery query;
    QString strQuery = "insert into asset (Item, Descr, Catagory, PartNo, Manufacturer) "
            "values('" + strItem + "', '" + strDesc + "', '" + strCatagory + "', '" + strPartNo + "', '" + strManufacturer + "')" ;
    if(!query.exec(strQuery))
        qDebug() << "Error running query:";

    return true ;
}

void Widget::on_btnStore_clicked()
{
    StoreItemInfo();
}
