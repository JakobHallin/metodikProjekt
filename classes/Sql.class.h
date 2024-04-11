#ifndef SQL_H
#define SQL_H

#include "Db.class.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QDebug>


class Sql {
private:
    //Db* db; //makes so I can have several Sql classes but just one connection.
    //can make Db global so i can allways reachit
public:
    //explicit Sql(Db* db  = nullptr);
    //Sql();
    QSqlQuery execute(const QString& sql);
    QSqlQuery prepareStatement(const QString& sql);

    //template<typename T>
    //void bind(QSqlQuery& stmt, const QString& index, const T& value);
    template<typename T>
    void bind(QSqlQuery& stmt, const QString& index, const T& value) {
        stmt.bindValue(index, value);
    }

    // Templated insert method for three parameters of the same type
    template<typename T>
    void insert(const QString& sql, T t1, T t2, T t3) {
        QSqlQuery stmt = prepareStatement(sql);
        bind(stmt, ":param1", t1);
        bind(stmt, ":param2", t2);
        bind(stmt, ":param3", t3);
        if (!stmt.exec()) {
            qDebug() << "Insert failed:" << stmt.lastError().text();
        }
    }


    // template<typename T>
   // void insert(const QString& sql, T t1, T t2, T t3);
};
#endif
