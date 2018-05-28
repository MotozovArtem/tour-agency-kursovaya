//
// Created by rienel on 28.05.18.
//

#include "RightMenuItem.h"


RightMenuItem::RightMenuItem(const QString &text, QListWidget *view, int type, Tables tables)
        : QListWidgetItem(text, view, type) {
    this->tables = tables;
}

RightMenuItem::RightMenuItem(QListWidget *view, int type, Tables tables) : QListWidgetItem(view, type),
                                                                                       tables(tables) {}

RightMenuItem::RightMenuItem(const QIcon &icon, const QString &text, QListWidget *view, int type,
                             Tables tables) : QListWidgetItem(icon, text, view, type), tables(tables) {}
