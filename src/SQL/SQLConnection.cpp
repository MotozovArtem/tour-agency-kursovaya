//
// Created by rienel on 01.05.18.
//

#include "SQLConnection.h"

SQLConnection::SQLConnection(const QString &driverName, const QString &dbName, const QString &username,
                             const QString &password) : driverName(driverName), dbName(dbName), username(username),
                                                        password(password) {}

SQLConnection::SQLConnection(const QString &dbName, const QString &username, const QString &password) : dbName(dbName),
                                                                                                        username(
                                                                                                                username),
                                                                                                        password(
                                                                                                                password) {
    this->driverName = "QPSQL";
    *connection = QSqlDatabase::addDatabase(this->driverName);
    connection->setDatabaseName(this->dbName);
    connection->setUserName(this->username);
    connection->setPassword(this->password);
}

SQLConnection::~SQLConnection() {
    delete this->password;
    delete this->username;
    delete this->dbName;
    if (this->connection->isOpen()) {
        this->connection->close();
    }
    delete this->connection;
}

const QString &SQLConnection::getDriverName() const {
    return driverName;
}

void SQLConnection::setDriverName(const QString &driverName) {
    SQLConnection::driverName = driverName;
}

const QString &SQLConnection::getDbName() const {
    return dbName;
}

void SQLConnection::setDbName(const QString &dbName) {
    SQLConnection::dbName = dbName;
}

const QString &SQLConnection::getUsername() const {
    return username;
}

void SQLConnection::setUsername(const QString &username) {
    SQLConnection::username = username;
}

const QString &SQLConnection::getPassword() const {
    return password;
}

void SQLConnection::setPassword(const QString &password) {
    SQLConnection::password = password;
}

QSqlDatabase *SQLConnection::getConnection() const {
    return connection;
}

void SQLConnection::setConnection(QSqlDatabase *connection) {
    SQLConnection::connection = connection;
}
