#ifndef DB_H
#define DB_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
/**
 * @class Db
 * @brief Manages the application's connection to the database.
 *
 * The Db class provides a static method to access a singleton-like
 * database connection, initializing it once when first requested.
 *
 * @note Uses Qt's QSqlDatabase for database interactions.
 */
class Db {
public:
    /**
     * @brief Returns a reference to the application's database connection.
     *
     * If the connection has not been initialized, it will initialize it first.
     *
     * @return QSqlDatabase The configured database connection.
     */
    static QSqlDatabase getConnection();

private:
    /**
     * @brief Initializes the database connection.
     *
     * Called internally once before the connection is first returned.
     */
    static void initialize();
    static bool isInitialized; /**< Tracks whether the database has been initialized. */
};

#endif // DB_H
