//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_DOCUMENTSFORTOURDAO_H
#define PSQLWORK_DOCUMENTSFORTOURDAO_H


#include "ModelDAO.h"
#include "../DocumentsForTour.h"

class DocumentsForTourDAO : public ModelDAO<DocumentsForTour *> {
public:
    virtual std::list<DocumentsForTour *> getAll() =0;

    virtual DocumentsForTour *getById(int id) =0;

    virtual void add(DocumentsForTour *model) =0;

    virtual void update(DocumentsForTour *model) =0;

    virtual void del(DocumentsForTour *model) =0;
};


#endif //PSQLWORK_DOCUMENTSFORTOURDAO_H
