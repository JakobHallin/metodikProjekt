#include "Db.class.h"

bool Db::isInitialized = false;

QSqlDatabase Db::getConnection()
{
    if (!isInitialized) {
        initialize();
    }

    return QSqlDatabase::database(); // Returns the default connection
}

void Db::initialize()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Or your specific database host
    db.setDatabaseName("metodik"); // Your database name
    db.setUserName("root"); // Your database username
    db.setPassword("hallin"); // Your database password
    db.setPort(3306); // Default MySQL/MariaDB port, change if necessary
    if (!db.open()) {
        qDebug() << "Error: connection with database failed:" << db.lastError().text();
    } else {
        qDebug() << "Database: connection ok";
        isInitialized = true;
    }
}
