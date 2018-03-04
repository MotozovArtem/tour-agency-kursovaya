//
// Created by rienel on 02.03.18.
//

#ifndef PSQLWORK_MODEL_H
#define PSQLWORK_MODEL_H


class Model {
protected:
    int id;
public:
    Model(int id);

    Model();

    virtual ~Model();

    int getId() const;

    void setId(int id);
};


#endif //PSQLWORK_MODEL_H
