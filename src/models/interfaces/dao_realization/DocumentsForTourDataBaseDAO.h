//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_DOCUMENTSFORTOURDATABASEDAO_H
#define PSQLWORK_DOCUMENTSFORTOURDATABASEDAO_H


#include "interfaces/DocumentsForTourDAO.h"

class DocumentsForTourDataBaseDAO: public DocumentsForTourDAO {
public:
    virtual QList<DocumentsForTour *> getAll();

    virtual DocumentsForTour *getById(int id);

    virtual void add(DocumentsForTour *model);

    virtual void update(DocumentsForTour *model);

    virtual void del(DocumentsForTour *model);

    virtual QList<DocumentsForTour *> getAllFilled();

};


#endif //PSQLWORK_DOCUMENTSFORTOURDATABASEDAO_H
