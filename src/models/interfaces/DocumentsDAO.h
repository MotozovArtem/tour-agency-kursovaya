//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_DOCUMENTSDAO_H
#define PSQLWORK_DOCUMENTSDAO_H


#include "ModelDAO.h"
#include "../Documents.h"

class DocumentsDAO : public ModelDAO<Documents *> {
public:
    virtual std::list<Documents *> getAll() =0;

    virtual Documents *getById(int id) =0;

    virtual void add(Documents *model) =0;

    virtual void update(Documents *model) =0;

    virtual void del(Documents *model) =0;
};


#endif //PSQLWORK_DOCUMENTSDAO_H
