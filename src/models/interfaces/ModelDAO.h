//
// Created by rienel on 02.03.18.
//

#ifndef PSQLWORK_MODELDAO_H
#define PSQLWORK_MODELDAO_H

#include <list>
#include "../Model.h"


template<class T>
class ModelDAO {
public:
    virtual std::list<Model> getAll()= 0;

    virtual T getById(int id)= 0;

    virtual void add(T model) = 0;

    virtual void update(T model)=0;

    virtual void del(T model)=0;

};


#endif //PSQLWORK_MODELDAO_H
