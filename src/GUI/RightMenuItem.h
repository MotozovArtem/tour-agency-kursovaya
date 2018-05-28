//
// Created by rienel on 28.05.18.
//

#ifndef PSQLWORK_RIGHTMENUITEM_H
#define PSQLWORK_RIGHTMENUITEM_H

#include <QtWidgets/QListWidgetItem>
#include "utils/Tables.h"

class RightMenuItem : public QListWidgetItem {
public:
    RightMenuItem(const QString &text, QListWidget *view, int type, Tables tables);

    RightMenuItem(QListWidget *view, int type, Tables tables);

    RightMenuItem(const QIcon &icon, const QString &text, QListWidget *view, int type, Tables tables);

    Tables tables;
};


#endif //PSQLWORK_RIGHTMENUITEM_H
