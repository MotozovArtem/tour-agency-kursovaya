//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_DOCUMENTTYPEDATABASEDAO_H
#define PSQLWORK_DOCUMENTTYPEDATABASEDAO_H


#include "interfaces/DocumentTypeDAO.h"

class DocumentTypeDataBaseDAO: public DocumentTypeDAO {
public:
    virtual QList<DocumentType *> getAll();

    virtual DocumentType *getById(int id);

    virtual void add(DocumentType *model);

    virtual void update(DocumentType *model);

    virtual void del(DocumentType *model);

    virtual QList<DocumentType *> getAllFilled();
};


#endif //PSQLWORK_DOCUMENTTYPEDATABASEDAO_H
