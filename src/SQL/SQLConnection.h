//
// Created by rienel on 01.05.18.
//

#ifndef PSQLWORK_SQLCONNECTION_H
#define PSQLWORK_SQLCONNECTION_H

#include <QtSql/QtSql>
#include <QString>

class SQLConnection {
private:
    QString driverName;
    QString dbName;
    QString username;
    QString password;
    QSqlDatabase connection;
public:
    SQLConnection(const QString &driverName, const QString &dbName, const QString &username, const QString &password);

    SQLConnection(const QString &dbName, const QString &username, const QString &password);

    const QString &getDriverName() const;

    void setDriverName(const QString &driverName);

    const QString &getDbName() const;

    void setDbName(const QString &dbName);

    const QString &getUsername() const;

    void setUsername(const QString &username);

    const QString &getPassword() const;

    void setPassword(const QString &password);

    QSqlDatabase getConnection() const;

    void setConnection(QSqlDatabase connection);

    virtual ~SQLConnection();
};


#endif //PSQLWORK_SQLCONNECTION_H
