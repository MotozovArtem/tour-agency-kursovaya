//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_DOCUMENTTYPEDAO_H
#define PSQLWORK_DOCUMENTTYPEDAO_H

#include "ModelDAO.h"
#include "../DocumentType.h"


class DocumentTypeDAO : public ModelDAO<DocumentType *> {
public:
    virtual std::list<DocumentType *> getAll() =0;

    virtual DocumentType *getById(int id) =0;

    virtual void add(DocumentType *model) =0;

    virtual void update(DocumentType *model) =0;

    virtual void del(DocumentType *model) =0;
};


#endif //PSQLWORK_DOCUMENTTYPEDAO_H
