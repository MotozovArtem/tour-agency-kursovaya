//
// Created by rienel on 29.05.18.
//

#ifndef PSQLWORK_EDITWINDOW_H
#define PSQLWORK_EDITWINDOW_H

#include "AddWindow.h"

class EditWindow: public AddWindow {

public:
    EditWindow(QWidget *parent, const Qt::WindowFlags &f, Tables table);

};


#endif //PSQLWORK_EDITWINDOW_H
