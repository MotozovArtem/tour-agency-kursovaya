//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_MAINTABWIDGET_H
#define PSQLWORK_MAINTABWIDGET_H

#include <QtWidgets/QTabWidget>
#include "utils/Tables.h"

#include "RightMenuItem.h"

class RightMenuWidget : public QListWidget {
Q_OBJECT
public:
    RightMenuWidget(QWidget *parent);


private slots:

    void selected(QListWidgetItem *listItem);

signals:

    void change(Tables);
};


#endif //PSQLWORK_MAINTABWIDGET_H
