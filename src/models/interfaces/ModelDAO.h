//
// Created by rienel on 02.03.18.
//

#ifndef PSQLWORK_MODELDAO_H
#define PSQLWORK_MODELDAO_H

#include <list>
#include <QtCore>
#include "../Model.h"


template<class T>
class ModelDAO {

};

template<class T>
class ModelDAO<T *> {
public:
    virtual QList<T *> getAll()= 0;

    virtual T *getById(int id)= 0;

    virtual void add(T *model) = 0;

    virtual void update(T *model)=0;

    virtual void del(T *model)=0;

    virtual QList<T *> getAllFilled()=0;
};


#endif //PSQLWORK_MODELDAO_H
