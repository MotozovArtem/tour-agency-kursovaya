//
// Created by rienel on 02.03.18.
//

#ifndef PSQLWORK_MODEL_H
#define PSQLWORK_MODEL_H


class Model {
private:
    int id;
public:
    Model(int id);
    Model();
    ~Model();
    int getId();
    void setId(int id);
};


#endif //PSQLWORK_MODEL_H
