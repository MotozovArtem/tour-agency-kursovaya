//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_DOCUMENTSDATABASEDAO_H
#define PSQLWORK_DOCUMENTSDATABASEDAO_H

#include "interfaces/DocumentsDAO.h"

class DocumentsDataBaseDAO: public DocumentsDAO {
public:
    virtual QList<Documents *> getAll();

    virtual Documents *getById(int id);

    virtual void add(Documents *model);

    virtual void update(Documents *model);

    virtual void del(Documents *model);

    virtual QList<Documents *> getAllFilled();
};


#endif //PSQLWORK_DOCUMENTSDATABASEDAO_H
