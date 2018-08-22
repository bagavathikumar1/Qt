/*
 * Database.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: baga
 */

#include "Database.h"
#include <QMessageBox>

Database::Database() {
	m_sqlDB = QSqlDatabase::addDatabase("QODBC");
    m_sqlDB.setDatabaseName("Driver={MySQL ODBC 5.1 Driver};DATABASE=ADTL;");
    m_sqlDB.setUserName("root");
    m_sqlDB.setPassword("Devasena83");

    if (!m_sqlDB.open()) {
        /*QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);*/
        QMessageBox::critical(0, "Error", "Database Error", QMessageBox::Cancel);
        return ;
    }

}

Database::~Database() {
	// TODO Auto-generated destructor stub
}


bool Database::GetCustomers(const QString& strQuery1)
{
    QSqlQuery query;
    QString strQuery = "SELECT Name FROM customer" ;
    if(!query.exec(strQuery))
    	qDebug() << "Error running query:";

    return true;
}
