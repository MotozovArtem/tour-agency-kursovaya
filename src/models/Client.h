//
// Created by rienel on 02.03.18.
//

#ifndef PSQLWORK_CLIENT_H
#define PSQLWORK_CLIENT_H

#include "Model.h"
#include <string>

class Client: public Model {
private:
    std::string* firstName;
    std::string* name;
    std::string* patronymic;
    std::string* birthday;
    std::string* birthPlace;
public:
    Client();
    Client(int id);
    Client(std::string* firstName, std::string* name, std::string* patronymic, std::string* birthday, std::string* birthPlace);
    Client(int id, std::string* firstName, std::string* name, std::string* patronymic, std::string* birthday, std::string* birthPlace);
    std::string* getFirstName();
    void setFirstName(std::string* firstName);
    std::string* getName();
    void setName(std::string* name);
    std::string* getPatronymic();
    void setPatronymic(std::string* patronymic);
    std::string* getBirthday();
    void setBirthday(std::string* birthday);


};


#endif //PSQLWORK_CLIENT_H
