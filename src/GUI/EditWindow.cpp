//
// Created by rienel on 29.05.18.
//

#include <models/interfaces/dao_realization/CityDataBaseDAO.h>
#include <models/interfaces/dao_realization/CityTypeDataBaseDAO.h>
#include <models/interfaces/dao_realization/ClientDataBaseDAO.h>
#include <models/interfaces/dao_realization/ClientRestDataBaseDAO.h>
#include <models/interfaces/dao_realization/ContractDataBaseDAO.h>
#include <models/interfaces/dao_realization/CountryDataBaseDAO.h>
#include <models/interfaces/dao_realization/DocumentTypeDataBaseDAO.h>
#include <models/interfaces/dao_realization/DocumentsDataBaseDAO.h>
#include <models/interfaces/dao_realization/DocumentsForTourDataBaseDAO.h>
#include <models/interfaces/dao_realization/FlightDataBaseDAO.h>
#include <models/interfaces/dao_realization/HotelDataBaseDAO.h>
#include <models/interfaces/dao_realization/HotelRoomDataBaseDAO.h>
#include <models/interfaces/dao_realization/HotelRoomTypeDataBaseDAO.h>
#include <models/interfaces/dao_realization/PlaceArrivalDataBaseDAO.h>
#include <models/interfaces/dao_realization/PlaceArrivalTypeDataBaseDAO.h>
#include <models/interfaces/dao_realization/ReservationDataBaseDAO.h>
#include <models/interfaces/dao_realization/ReservByAgreementDataBaseDAO.h>
#include <models/interfaces/dao_realization/SightDataBaseDAO.h>
#include <models/interfaces/dao_realization/StatusDataBaseDAO.h>
#include <models/interfaces/dao_realization/TicketDataBaseDAO.h>
#include <models/interfaces/dao_realization/TourDataBaseDAO.h>
#include <models/interfaces/dao_realization/TourTypeDataBaseDAO.h>
#include <models/interfaces/dao_realization/TransportNodeDataBaseDAO.h>
#include <models/interfaces/dao_realization/TransportNodeTypeDataBaseDAO.h>

#include "EditWindow.h"

EditWindow::EditWindow(QWidget *parent, const Qt::WindowFlags &f, Tables table, int id) : AddWindow(parent, f, table) {
    this->id = id;
    fillEditFields();
}

void EditWindow::fillEditFields() {
    switch (this->currentTable) {
        case Tables::TCity:
            _fillEditFields<City, CityDataBaseDAO>();
            break;
        case Tables::TCityType:
            _fillEditFields<CityType, CityTypeDataBaseDAO>();
            break;
        case Tables::TClient:
            _fillEditFields<Client, ClientDataBaseDAO>();
            break;
        case Tables::TClientRest:
            _fillEditFields<ClientRest, ClientRestDataBaseDAO>();
            break;
        case Tables::TContract:
            _fillEditFields<Contract, ContractDataBaseDAO>();
            break;
        case Tables::TCountry:
            _fillEditFields<Country, CountryDataBaseDAO>();
            break;
        case Tables::TDocuments:
            _fillEditFields<Documents, DocumentsDataBaseDAO>();
            break;
        case Tables::TDocumentsForTour:
            _fillEditFields<DocumentsForTour, DocumentsForTourDataBaseDAO>();
            break;
        case Tables::TDocumentsType:
            _fillEditFields<DocumentType, DocumentTypeDataBaseDAO>();
            break;
        case Tables::TFlight:
            _fillEditFields<Flight, FlightDataBaseDAO>();
            break;
        case Tables::THotel:
            _fillEditFields<Hotel, HotelDataBaseDAO>();
            break;
        case Tables::THotelRoom:
            _fillEditFields<HotelRoom, HotelRoomDataBaseDAO>();
            break;
        case Tables::THotelRoomType:
            _fillEditFields<HotelRoomType, HotelRoomTypeDataBaseDAO>();
            break;
        case Tables::TPlaceArrival:
            _fillEditFields<PlaceArrival, PlaceArrivalDataBaseDAO>();
            break;
        case Tables::TPlaceArrivalType:
            _fillEditFields<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>();
            break;
        case Tables::TReservation:
            _fillEditFields<Reservation, ReservationDataBaseDAO>();
            break;
        case Tables::TReservByAgreement:
            _fillEditFields<ReservByAgreement, ReservByAgreementDataBaseDAO>();
            break;
        case Tables::TSight:
            _fillEditFields<Sight, SightDataBaseDAO>();
            break;
        case Tables::TStatus:
            _fillEditFields<Status, StatusDataBaseDAO>();
            break;
        case Tables::TTicket:
            _fillEditFields<Ticket, TicketDataBaseDAO>();
            break;
        case Tables::TTour:
            _fillEditFields<Tour, TourDataBaseDAO>();
            break;
        case Tables::TTourType:
            _fillEditFields<TourType, TourTypeDataBaseDAO>();
            break;
        case Tables::TTransportNode:
            _fillEditFields<TransportNode, TransportNodeDataBaseDAO>();
            break;
        case Tables::TTransportNodeType:
            _fillEditFields<TransportNodeType, TransportNodeTypeDataBaseDAO>();
            break;
    }
}

