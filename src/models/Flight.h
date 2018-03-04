//
// Created by rienel on 04.03.18.
//

#ifndef PSQLWORK_FLIGHT_H
#define PSQLWORK_FLIGHT_H

#include "Model.h"
#include <string>

class Flight : public Model {
private:
    std::string* purchaseDate;
    int flightSer;
    std::string* arrivalDate;
    std::string* departureDate;
    std::string* arrivalTime;
    std::string* departureTime;
    std::string* airportOfArrival;
    std::string* airportOfDeparture;
public:
    Flight(int id, std::string *purchaseDate, int flightSer, std::string *arrivalDate, std::string *departureDate,
           std::string *arrivalTime, std::string *departureTime, std::string *airportOfArrival,
           std::string *airportOfDeparture);

    Flight(std::string *purchaseDate, int flightSer, std::string *arrivalDate, std::string *departureDate,
           std::string *arrivalTime, std::string *departureTime, std::string *airportOfArrival,
           std::string *airportOfDeparture);

    Flight(int id);

    Flight();

    std::string *getPurchaseDate() const;

    void setPurchaseDate(std::string *purchaseDate);

    int getFlightSer() const;

    void setFlightSer(int flightSer);

    std::string *getArrivalDate() const;

    void setArrivalDate(std::string *arrivalDate);

    std::string *getDepartureDate() const;

    void setDepartureDate(std::string *departureDate);

    std::string *getArrivalTime() const;

    void setArrivalTime(std::string *arrivalTime);

    std::string *getDepartureTime() const;

    void setDepartureTime(std::string *departureTime);

    std::string *getAirportOfArrival() const;

    void setAirportOfArrival(std::string *airportOfArrival);

    std::string *getAirportOfDeparture() const;

    void setAirportOfDeparture(std::string *airportOfDeparture);

    virtual ~Flight();
};


#endif //PSQLWORK_FLIGHT_H
