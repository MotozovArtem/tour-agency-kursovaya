//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_TOURDAO_H
#define PSQLWORK_TOURDAO_H

#include "ModelDAO.h"
#include "../Tour.h"

class TourDAO : public ModelDAO<Tour *> {
public:
    virtual std::list<Tour *> getAll() =0;

    virtual Tour *getById(int id) =0;

    virtual void add(Tour *model) =0;

    virtual void update(Tour *model) =0;

    virtual void del(Tour *model) =0;
};


#endif //PSQLWORK_TOURDAO_H
