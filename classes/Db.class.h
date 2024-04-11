#ifndef DB_H
#define DB_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>

class Db {
public:
    static QSqlDatabase getConnection();

private:
    static void initialize();
    static bool isInitialized;
};

#endif // DB_H
