//
// Created by rienel on 04.03.18.
//

#include "Flight.h"

Flight::Flight(int id, std::string *purchaseDate, int flightSer, std::string *arrivalDate, std::string *departureDate,
               std::string *arrivalTime, std::string *departureTime, std::string *airportOfArrival,
               std::string *airportOfDeparture) : Model(id), purchaseDate(purchaseDate), flightSer(flightSer),
                                                  arrivalDate(arrivalDate), departureDate(departureDate),
                                                  arrivalTime(arrivalTime), departureTime(departureTime),
                                                  airportOfArrival(airportOfArrival),
                                                  airportOfDeparture(airportOfDeparture) {}

Flight::Flight(std::string *purchaseDate, int flightSer, std::string *arrivalDate, std::string *departureDate,
               std::string *arrivalTime, std::string *departureTime, std::string *airportOfArrival,
               std::string *airportOfDeparture) : purchaseDate(purchaseDate), flightSer(flightSer),
                                                  arrivalDate(arrivalDate), departureDate(departureDate),
                                                  arrivalTime(arrivalTime), departureTime(departureTime),
                                                  airportOfArrival(airportOfArrival),
                                                  airportOfDeparture(airportOfDeparture) {}

Flight::Flight(int id) : Model(id) {}

Flight::Flight() = default;

Flight::~Flight() = default;

std::string *Flight::getPurchaseDate() const {
    return purchaseDate;
}

void Flight::setPurchaseDate(std::string *purchaseDate) {
    Flight::purchaseDate = purchaseDate;
}

int Flight::getFlightSer() const {
    return flightSer;
}

void Flight::setFlightSer(int flightSer) {
    Flight::flightSer = flightSer;
}

std::string *Flight::getArrivalDate() const {
    return arrivalDate;
}

void Flight::setArrivalDate(std::string *arrivalDate) {
    Flight::arrivalDate = arrivalDate;
}

std::string *Flight::getDepartureDate() const {
    return departureDate;
}

void Flight::setDepartureDate(std::string *departureDate) {
    Flight::departureDate = departureDate;
}

std::string *Flight::getArrivalTime() const {
    return arrivalTime;
}

void Flight::setArrivalTime(std::string *arrivalTime) {
    Flight::arrivalTime = arrivalTime;
}

std::string *Flight::getDepartureTime() const {
    return departureTime;
}

void Flight::setDepartureTime(std::string *departureTime) {
    Flight::departureTime = departureTime;
}

std::string *Flight::getAirportOfArrival() const {
    return airportOfArrival;
}

void Flight::setAirportOfArrival(std::string *airportOfArrival) {
    Flight::airportOfArrival = airportOfArrival;
}

std::string *Flight::getAirportOfDeparture() const {
    return airportOfDeparture;
}

void Flight::setAirportOfDeparture(std::string *airportOfDeparture) {
    Flight::airportOfDeparture = airportOfDeparture;
}
