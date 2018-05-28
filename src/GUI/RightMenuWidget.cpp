//
// Created by rienel on 27.05.18.
//

#include "RightMenuWidget.h"
#include <QtWidgets>

RightMenuWidget::RightMenuWidget(QWidget *parent) : QListWidget(parent) {
    connect(this, SIGNAL(itemClicked(QListWidgetItem * )), this, SLOT(selected(QListWidgetItem * )));
}


Q_SLOT void RightMenuWidget::selected(QListWidgetItem *listItem) {
    RightMenuItem *item = dynamic_cast<RightMenuItem *>(listItem);
    emit change(item->tables);
}
