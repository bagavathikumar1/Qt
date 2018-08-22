/*
 * Database.h
 *
 *  Created on: Nov 9, 2012
 *      Author: baga
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qdebug.h>

class Database {
public:
	Database();
	virtual ~Database();

private:
	QSqlDatabase m_sqlDB ;

public:
	bool GetCustomers(const QString&) ;
};

#endif /* DATABASE_H_ */
