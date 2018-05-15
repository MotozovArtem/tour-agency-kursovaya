//
// Created by rienel on 01.05.18.
//

#ifndef PSQLWORK_LOGGER_H
#define PSQLWORK_LOGGER_H


#include <QObject>
#include <QPlainTextEdit>
#include <QIODevice>
#include <QtCore/QDate>

class Logger : public QObject {
Q_OBJECT
public:
    Logger(QObject *parent, QString fileName, QPlainTextEdit *editor = nullptr);

    ~Logger();

private:
    QFile *file;
    QPlainTextEdit *editor;
public slots:

    void write(const QString &value);

};


#endif //PSQLWORK_LOGGER_H
