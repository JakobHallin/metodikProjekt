#include "Db.class.h"

#include <QProcessEnvironment>

bool Db::isInitialized = false;

QSqlDatabase Db::getConnection()
{
    if (!isInitialized) {
        initialize();
    }

    return QSqlDatabase::database();
}

void Db::initialize()
{
    const QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

    const QString host = env.value("DB_HOST", "localhost");
    const QString database = env.value("DB_NAME", "metodik");
    const QString username = env.value("DB_USER", "root");
    const QString password = env.value("DB_PASSWORD");
    const int port = env.value("DB_PORT", "3306").toInt();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(username);
    db.setPassword(password);
    db.setPort(port);

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return;
    }

    qDebug() << "Database connection established";
    isInitialized = true;
}