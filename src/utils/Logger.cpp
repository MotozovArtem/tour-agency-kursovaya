//
// Created by rienel on 01.05.18.
//


#include <QtCore/QDateTime>
#include <QtCore/QTextStream>
#include "Logger.h"


Logger::Logger(QObject *parent, QString fileName, QPlainTextEdit *editor) {
    this->editor = editor;
    if (!fileName.isEmpty()) {
        this->file = new QFile;
        this->file->setFileName(fileName);
        this->file->open(QIODevice::Append | QIODevice::Text);
    }
}

void Logger::write(const QString &value) {
    QString text =
            QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + value + "\n";
    QTextStream out(this->file);
    out.setCodec("UTF-8");
    if (file != nullptr) {
        out << text;
    }
    if (this->editor != nullptr) {
        this->editor->appendPlainText(text);
    }
}

Logger::~Logger() {
    if (file != nullptr) {
        file->close();
    }
}


