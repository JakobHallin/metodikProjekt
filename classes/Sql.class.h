#ifndef SQL_H
#define SQL_H

#include "Db.class.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QDebug>

/**
 * @class Sql
 * @brief Provides simplified access to executing and preparing SQL queries using Qt's SQL module.
 *
 * The Sql class offers methods for executing raw SQL, preparing parameterized statements,
 * binding values generically, and performing templated inserts. It uses the connection from @ref Db.
 */
class Sql {
private:
    //Db* db; //makes so I can have several Sql classes but just one connection.
    //can make Db global so i can allways reachit
public:
    /**
     * @brief Executes a raw SQL query.
     * @param sql The SQL string to execute.
     * @return QSqlQuery The result of the executed query.
     */
    QSqlQuery execute(const QString& sql);

    /**
     * @brief Prepares a SQL statement for parameter binding.
     * @param sql The SQL statement with placeholders (e.g., ":param1").
     * @return QSqlQuery The prepared query object.
     */
    QSqlQuery prepareStatement(const QString& sql);

    /**
     * @brief Binds a value to a named placeholder in a prepared statement.
     * @tparam T The type of the value to bind.
     * @param stmt The prepared QSqlQuery.
     * @param index The placeholder name (e.g., ":param1").
     * @param value The value to bind.
     */
    template<typename T>
    void bind(QSqlQuery& stmt, const QString& index, const T& value) {
        stmt.bindValue(index, value);
    }

    /**
     * @brief Inserts three values into a table using a parameterized query.
     *
     * The SQL query should include placeholders `:param1`, `:param2`, and `:param3`.
     *
     * @tparam T The type of all three values (must be the same).
     * @param sql The SQL insert statement.
     * @param t1 First value to insert.
     * @param t2 Second value to insert.
     * @param t3 Third value to insert.
     */
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
};
#endif
