//
// Created by rienel on 28.05.18.
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


#include "AddWindow.h"


AddWindow::AddWindow(QWidget *parent, const Qt::WindowFlags &f, Tables table) : QDialog(parent, f) {
    this->currentTable = table;
    this->formLayout = new QFormLayout();

    initDialogForm();

    this->okButton = new QPushButton("OK");
    this->cancelButton = new QPushButton("Cancel");
    connect(this->okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(this->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    this->formLayout->addRow(this->okButton, this->cancelButton);

    this->setLayout(this->formLayout);
    this->show();
}

const QList<QWidget *> &AddWindow::getEditList() const {
    return editList;
}

void AddWindow::setEditList(const QList<QWidget *> &editList) {
    AddWindow::editList = editList;
}

const QList<QLabel *> &AddWindow::getLabelList() const {
    return labelList;
}

void AddWindow::setLabelList(const QList<QLabel *> &labelList) {
    AddWindow::labelList = labelList;
}

QPushButton *AddWindow::getOkButton() const {
    return okButton;
}

void AddWindow::setOkButton(QPushButton *okButton) {
    AddWindow::okButton = okButton;
}

QPushButton *AddWindow::getCancelButton() const {
    return cancelButton;
}

void AddWindow::setCancelButton(QPushButton *cancelButton) {
    AddWindow::cancelButton = cancelButton;
}

QFormLayout *AddWindow::getFormLayout() const {
    return formLayout;
}

void AddWindow::setFormLayout(QFormLayout *formLayout) {
    AddWindow::formLayout = formLayout;
}

void AddWindow::initDialogForm() {
    switch (this->currentTable) {
        case Tables::TCity:
            _initDialogForm<City>();
            break;
        case Tables::TCityType:
            _initDialogForm<CityType>();
            break;
        case Tables::TClient:
            _initDialogForm<Client>();
            break;
        case Tables::TClientRest:
            _initDialogForm<ClientRest>();
            break;
        case Tables::TContract:
            _initDialogForm<Contract>();
            break;
        case Tables::TCountry:
            _initDialogForm<Country>();
            break;
        case Tables::TDocuments:
            _initDialogForm<Documents>();
            break;
        case Tables::TDocumentsForTour:
            _initDialogForm<DocumentsForTour>();
            break;
        case Tables::TDocumentsType:
            _initDialogForm<DocumentType>();
            break;
        case Tables::TFlight:
            _initDialogForm<Flight>();
            break;
        case Tables::THotel:
            _initDialogForm<Hotel>();
            break;
        case Tables::THotelRoom:
            _initDialogForm<HotelRoom>();
            break;
        case Tables::THotelRoomType:
            _initDialogForm<HotelRoomType>();
            break;
        case Tables::TPlaceArrival:
            _initDialogForm<PlaceArrival>();
            break;
        case Tables::TPlaceArrivalType:
            _initDialogForm<PlaceArrivalType>();
            break;
        case Tables::TReservation:
            _initDialogForm<Reservation>();
            break;
        case Tables::TReservByAgreement:
            _initDialogForm<ReservByAgreement>();
            break;
        case Tables::TSight:
            _initDialogForm<Sight>();
            break;
        case Tables::TStatus:
            _initDialogForm<Status>();
            break;
        case Tables::TTicket:
            _initDialogForm<Ticket>();
            break;
        case Tables::TTour:
            _initDialogForm<Tour>();
            break;
        case Tables::TTourType:
            _initDialogForm<TourType>();
            break;
        case Tables::TTransportNode:
            _initDialogForm<TransportNode>();
            break;
        case Tables::TTransportNodeType:
            _initDialogForm<TransportNodeType>();
            break;
    }
}

AddWindow::~AddWindow() {
    delete this->formLayout;
    delete this->okButton;
    delete this->cancelButton;

    foreach(QWidget *widget, this->editList){
        delete widget;
    }
    foreach(QLabel *label, this->labelList){
        delete label;
    }
}
