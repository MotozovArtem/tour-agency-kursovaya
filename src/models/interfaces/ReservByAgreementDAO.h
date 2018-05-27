//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_RESERVBYAGREEMENTDAO_H
#define PSQLWORK_RESERVBYAGREEMENTDAO_H

#include "ModelDAO.h"
#include "../ReservByAgreement.h"

class ReservByAgreementDAO : public ModelDAO<ReservByAgreement *> {
public:
    virtual QList<ReservByAgreement *> getAll() =0;

    virtual ReservByAgreement *getById(int id) =0;

    virtual void add(ReservByAgreement *model) =0;

    virtual void update(ReservByAgreement *model) =0;

    virtual void del(ReservByAgreement *model) =0;

    virtual QList<ReservByAgreement *> getAllFilled() =0;
};


#endif //PSQLWORK_RESERVBYAGREEMENTDAO_H
