#include "Sql.class.h"
//Sql::Sql(Db* db) : db(db) {}
//Sql::Sql(){this->db = *db->getConnection();}
//dont need db
QSqlQuery Sql::execute(const QString& sql) {
    QSqlQuery query(Db::getConnection());
    //call prepare first
    //query.prepare(sql);

    if (!query.exec(sql)) {
        qDebug() << "Execute failed:" << query.lastError().text();
    }
    return query;
}

// Definitions for prepareStatement, execute, and bind methods (same as before)
QSqlQuery Sql::prepareStatement(const QString& sql) {

    QSqlQuery query(Db::getConnection());
    if (!query.prepare(sql)) {
        qDebug() << "Prepare failed:" << query.lastError().text();
    }
    return query;
}
// Templated insert method implementation
/*template<typename T>
void Sql::bind(QSqlQuery& stmt, const QString& index, const T& value) {
    stmt.bindValue(index, value);
}*/
/*
void Sql::bind(QSqlQuery& stmt, QString index , const T& value) {
    stmt.bindValue(index, value);
}
*/
/*
template<typename T>
void Sql::insert(const QString& sql, T t1, T t2, T t3) {
    QSqlQuery stmt = prepareStatement(sql);
    bind(stmt, ":param1", t1);
    bind(stmt, ":param2", t2);
    bind(stmt, ":param3", t3);
    if (!stmt.exec()) {
        qDebug() << "Insert failed:" << stmt.lastError().text();
    }
}
*/
// Explicit template instantiations for bind, if not defined within the header
/*
template void Sql::bind<int>(sqlite3_stmt*, int, const int&);
template void Sql::bind<double>(sqlite3_stmt*, int, const double&);
template void Sql::bind<std::string>(sqlite3_stmt*, int, const std::string&);

// Explicit template instantiations for insert
template void Sql::insert<int>(const std::string&, int, int, int);
template void Sql::insert<double>(const std::string&, double, double, double);
template void Sql::insert<std::string>(const std::string&, std::string, std::string, std::string);
*/
