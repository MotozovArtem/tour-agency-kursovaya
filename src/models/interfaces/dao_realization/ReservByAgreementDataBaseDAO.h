//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_RESERVBYAGREEMENTDATABASEDAO_H
#define PSQLWORK_RESERVBYAGREEMENTDATABASEDAO_H

#include "interfaces/ReservByAgreementDAO.h"

class ReservByAgreementDataBaseDAO: public ReservByAgreementDAO {
public:
    virtual QList<ReservByAgreement *> getAll();

    virtual ReservByAgreement *getById(int id);

    virtual void add(ReservByAgreement *model);

    virtual void update(ReservByAgreement *model);

    virtual void del(ReservByAgreement *model);

    virtual QList<ReservByAgreement *> getAllFilled();
};


#endif //PSQLWORK_RESERVBYAGREEMENTDATABASEDAO_H
