//
// Created by rienel on 04.05.18.
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

#include "MainWindow.h"


MainWindow::MainWindow(QMainWindow *pwgt) : QMainWindow(pwgt) {

    this->mainWidget = new QWidget();
    this->mainLayout = new QGridLayout(this->mainWidget);


    this->pTable = new QTableWidget(this->mainWidget);
    this->pButton = new QPushButton(this->mainWidget);
    this->rightMenu = new RightMenuWidget(this->mainWidget);


    initRightMenu();
    this->mainLayout->addWidget(this->pTable, 0, 0);
    this->mainLayout->addWidget(this->rightMenu, 0, 1);

    this->menu = new QMenuBar;
    QMenu *files = new QMenu("&Files");
    menu->addMenu(files);
    QAction *exit = new QAction("&Close");
    connect(exit, &QAction::triggered, this, &MainWindow::close);
    files->addAction(exit);

    connect(this->rightMenu, SIGNAL(change(Tables)), this, SLOT(renderTable(Tables)));

    this->setCentralWidget(this->mainWidget);
    this->setMenuBar(menu);
}

QTableWidget *MainWindow::getPTable() const {
    return pTable;
}

void MainWindow::setPTable(QTableWidget *pTable) {
    MainWindow::pTable = pTable;
}

QPushButton *MainWindow::getPButton() const {
    return pButton;
}

void MainWindow::setPButton(QPushButton *pButton) {
    MainWindow::pButton = pButton;
}


MainWindow::~MainWindow() {
    delete this->pButton;
    delete this->pTable;
    delete this->rightMenu;
    delete this->menu;
}


void MainWindow::renderTable(Tables tables) {
    switch (tables) {
        case Tables::TCity:
            _renderTable<City, CityDataBaseDAO>();
            break;
        case Tables::TCityType:
            _renderTable<CityType, CityTypeDataBaseDAO>();
            break;
        case Tables::TClient:
            _renderTable<Client, ClientDataBaseDAO>();
            break;
        case Tables::TClientRest:
            _renderTable<ClientRest, ClientRestDataBaseDAO>();
            break;
        case Tables::TContract:
            _renderTable<Contract, ContractDataBaseDAO>();
            break;
        case Tables::TCountry:
            _renderTable<Country, CountryDataBaseDAO>();
            break;
        case Tables::TDocuments:
            _renderTable<Documents, DocumentsDataBaseDAO>();
            break;
        case Tables::TDocumentsForTour:
            _renderTable<DocumentsForTour, DocumentsForTourDataBaseDAO>();
            break;
        case Tables::TDocumentsType:
            _renderTable<DocumentType, DocumentTypeDataBaseDAO>();
            break;
        case Tables::TFlight:
            _renderTable<Flight, FlightDataBaseDAO>();
            break;
        case Tables::THotel:
            _renderTable<Hotel, HotelDataBaseDAO>();
            break;
        case Tables::THotelRoom:
            _renderTable<HotelRoom, HotelRoomDataBaseDAO>();
            break;
        case Tables::THotelRoomType:
            _renderTable<HotelRoomType, HotelRoomTypeDataBaseDAO>();
            break;
        case Tables::TPlaceArrival:
            _renderTable<PlaceArrival, PlaceArrivalDataBaseDAO>();
            break;
        case Tables::TPlaceArrivalType:
            _renderTable<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>();
            break;
        case Tables::TReservation:
            _renderTable<Reservation, ReservationDataBaseDAO>();
            break;
        case Tables::TReservByAgreement:
            _renderTable<ReservByAgreement, ReservByAgreementDataBaseDAO>();
            break;
        case Tables::TSight:
            _renderTable<Sight, SightDataBaseDAO>();
            break;
        case Tables::TStatus:
            _renderTable<Status, StatusDataBaseDAO>();
            break;
        case Tables::TTicket:
            _renderTable<Ticket, TicketDataBaseDAO>();
            break;
        case Tables::TTour:
            _renderTable<Tour, TourDataBaseDAO>();
            break;
        case Tables::TTourType:
            _renderTable<TourType, TourTypeDataBaseDAO>();
            break;
        case Tables::TTransportNode:
            _renderTable<TransportNode, TransportNodeDataBaseDAO>();
            break;
        case Tables::TTransportNodeType:
            _renderTable<TransportNodeType, TransportNodeTypeDataBaseDAO>();
            break;
    }
}

void MainWindow::initRightMenu() {
    QStringList tables;
    tables << "City" << "CityType" << "Client" << "ClientRest" <<
           "Contract" << "Country" << "Documents" << "DocumentsForTour" << "DocumentsType" <<
           "Flight" << "Hotel" << "HotelRoom" << "HotelRoomType" <<
           "PlaceArrival" << "PlaceArrivalType" << "Reservation" << "ReservByAgreement" << "Sight" <<
           "Status" << "Ticket" << "Tour" << "TourType" << "TransportNode" << "TransportNodeType";
    int i = 0;
            foreach(QString tableName, tables) {
            new RightMenuItem(tableName, rightMenu, 1, (Tables) i);
            i++;
        }
}

RightMenuWidget *MainWindow::getRightMenu() const {
    return rightMenu;
}

void MainWindow::setRightMenu(RightMenuWidget *rightMenu) {
    MainWindow::rightMenu = rightMenu;
}
