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

#include <iostream>

MainWindow::MainWindow(QMainWindow *pwgt) : QMainWindow(pwgt) {

    this->mainWidget = new QWidget();
    this->mainLayout = new QGridLayout(this->mainWidget);
    this->currentTable = Tables::TCity;


    this->pTable = new QTableWidget(this->mainWidget);
//    this->pButton = new QPushButton(this->mainWidget);
    this->toolBar = new QToolBar();
    initToolBar();

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

//QPushButton *MainWindow::getPButton() const {
//    return pButton;
//}
//
//void MainWindow::setPButton(QPushButton *pButton) {
//    MainWindow::pButton = pButton;
//}


MainWindow::~MainWindow() {
//    delete this->pButton;
    delete this->pTable;
    delete this->rightMenu;
    delete this->menu;
    delete this->toolBar;

            foreach(QAction *actionMember, this->actionList) {
            delete actionMember;
        }
}


void MainWindow::renderTable(Tables tables) {
    this->currentTable = tables;
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
    tables << "City" << "City Type" << "Client" << "Client Rest" <<
           "Contract" << "Country" << "Documents" << "Documents For Tour" << "Documents Type" <<
           "Flight" << "Hotel" << "Hotel Room" << "Hotel Room Type" <<
           "Place Arrival" << "Place Arrival Type" << "Reservation" << "Reservation By Agreement" << "Sight" <<
           "Status" << "Ticket" << "Tour" << "Tour Type" << "Transport Node" << "Transport Node Type";
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

void MainWindow::initToolBar() {
    QAction *action = new QAction(QPixmap(":add.png"), "Add to selected table");
    connect(action, SIGNAL(triggered()), this, SLOT(addRow()));
    this->actionList << action;

    action = new QAction(QPixmap(":edit.png"), "Edit selected");
    connect(action, SIGNAL(triggered()), this, SLOT(editRow()));
    this->actionList << action;

    action = new QAction(QPixmap(":del.png"), "Delete selected row");
    connect(action, SIGNAL(triggered()), this, SLOT(deleteRow()));
    this->actionList << action;

            foreach(QAction *actionMember, this->actionList) {
            this->toolBar->addAction(actionMember);
        }
    this->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
}

void MainWindow::addRow() {
//    std::cout << "Add row slot\n";
    AddWindow *addWindow = new AddWindow(this, Qt::Window | Qt::WindowSystemMenuHint, this->currentTable);
    int exit_code = addWindow->exec();
//    std::cout << exit_code << "\n";
    if (exit_code == 1) {
        getValuesFromDialog(addWindow);
    } else {
        std::cout << "REJECTED\n";
    }
    delete addWindow;
}

void MainWindow::editRow() {
    std::cout << "edit row slot\n";
}

void MainWindow::deleteRow() {
    std::cout << "delete row slot\n";
}

void MainWindow::addInDataBase() {
//    switch (this->currentTable) {
//        case Tables::TCity:
//            _addInDataBase<City, CityDataBaseDAO>();
//            break;
//        case Tables::TCityType:
//            _addInDataBase<CityType, CityTypeDataBaseDAO>();
//            break;
//        case Tables::TClient:
//            _addInDataBase<Client, ClientDataBaseDAO>();
//            break;
//        case Tables::TClientRest:
//            _addInDataBase<ClientRest, ClientRestDataBaseDAO>();
//            break;
//        case Tables::TContract:
//            _addInDataBase<Contract, ContractDataBaseDAO>();
//            break;
//        case Tables::TCountry:
//            _addInDataBase<Country, CountryDataBaseDAO>();
//            break;
//        case Tables::TDocuments:
//            _addInDataBase<Documents, DocumentsDataBaseDAO>();
//            break;
//        case Tables::TDocumentsForTour:
//            _addInDataBase<DocumentsForTour, DocumentsForTourDataBaseDAO>();
//            break;
//        case Tables::TDocumentsType:
//            _addInDataBase<DocumentType, DocumentTypeDataBaseDAO>();
//            break;
//        case Tables::TFlight:
//            _addInDataBase<Flight, FlightDataBaseDAO>();
//            break;
//        case Tables::THotel:
//            _addInDataBase<Hotel, HotelDataBaseDAO>();
//            break;
//        case Tables::THotelRoom:
//            _addInDataBase<HotelRoom, HotelRoomDataBaseDAO>();
//            break;
//        case Tables::THotelRoomType:
//            _addInDataBase<HotelRoomType, HotelRoomTypeDataBaseDAO>();
//            break;
//        case Tables::TPlaceArrival:
//            _addInDataBase<PlaceArrival, PlaceArrivalDataBaseDAO>();
//            break;
//        case Tables::TPlaceArrivalType:
//            _addInDataBase<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>();
//            break;
//        case Tables::TReservation:
//            _addInDataBase<Reservation, ReservationDataBaseDAO>();
//            break;
//        case Tables::TReservByAgreement:
//            _addInDataBase<ReservByAgreement, ReservByAgreementDataBaseDAO>();
//            break;
//        case Tables::TSight:
//            _addInDataBase<Sight, SightDataBaseDAO>();
//            break;
//        case Tables::TStatus:
//            _addInDataBase<Status, StatusDataBaseDAO>();
//            break;
//        case Tables::TTicket:
//            _addInDataBase<Ticket, TicketDataBaseDAO>();
//            break;
//        case Tables::TTour:
//            _addInDataBase<Tour, TourDataBaseDAO>();
//            break;
//        case Tables::TTourType:
//            _addInDataBase<TourType, TourTypeDataBaseDAO>();
//            break;
//        case Tables::TTransportNode:
//            _addInDataBase<TransportNode, TransportNodeDataBaseDAO>();
//            break;
//        case Tables::TTransportNodeType:
//            _addInDataBase<TransportNodeType, TransportNodeTypeDataBaseDAO>();
//            break;
//    }
}

void MainWindow::getValuesFromDialog(AddWindow *window) {
    QList<QWidget *> editList = window->getEditList();
    switch (this->currentTable) {
        case Tables::TCity: {
            City *city = _getValuesFromDialog<City>(window);
            _addInDataBase<City, CityDataBaseDAO>(city);
            delete city;
            break;
        }
        case Tables::TCityType: {
            CityType *cityType = _getValuesFromDialog<CityType>(window);
            _addInDataBase<CityType, CityTypeDataBaseDAO>(cityType);
            delete cityType;
            break;
        }
        case Tables::TClient: {
            Client *client = _getValuesFromDialog<Client>(window);
            _addInDataBase<Client, ClientDataBaseDAO>(client);
            delete client;
            break;
        }
        case Tables::TClientRest: {
            ClientRest *clientRest = _getValuesFromDialog<ClientRest>(window);
            _addInDataBase<ClientRest, ClientRestDataBaseDAO>(clientRest);
            delete clientRest;
            break;
        }
        case Tables::TContract: {
            Contract *contract = _getValuesFromDialog<Contract>(window);
            _addInDataBase<Contract, ContractDataBaseDAO>(contract);
            delete contract;
            break;
        }
        case Tables::TCountry: {
            Country *country = _getValuesFromDialog<Country>(window);
            _addInDataBase<Country, CountryDataBaseDAO>(country);
            delete country;
            break;
        }
        case Tables::TDocuments: {
            Documents *document = _getValuesFromDialog<Documents>(window);
            _addInDataBase<Documents, DocumentsDataBaseDAO>(document);
            delete document;
            break;
        }
        case Tables::TDocumentsForTour: {
            DocumentsForTour *documentsForTour = _getValuesFromDialog<DocumentsForTour>(window);
            _addInDataBase<DocumentsForTour, DocumentsForTourDataBaseDAO>(documentsForTour);
            delete documentsForTour;
            break;
        }
        case Tables::TDocumentsType: {
            DocumentType *documentType = _getValuesFromDialog<DocumentType>(window);
            _addInDataBase<DocumentType, DocumentTypeDataBaseDAO>(documentType);
            delete documentType;
            break;
        }
        case Tables::TFlight: {
            Flight *flight = _getValuesFromDialog<Flight>(window);
            _addInDataBase<Flight, FlightDataBaseDAO>(flight);
            delete flight;
            break;
        }
        case Tables::THotel: {
            Hotel *hotel = _getValuesFromDialog<Hotel>(window);
            _addInDataBase<Hotel, HotelDataBaseDAO>(hotel);
            delete hotel;
            break;
        }
        case Tables::THotelRoom: {
            HotelRoom *hotelRoom = _getValuesFromDialog<HotelRoom>(window);
            _addInDataBase<HotelRoom, HotelRoomDataBaseDAO>(hotelRoom);
            delete hotelRoom;
            break;
        }
        case Tables::THotelRoomType: {
            HotelRoomType *hotelRoomType = _getValuesFromDialog<HotelRoomType>(window);
            _addInDataBase<HotelRoomType, HotelRoomTypeDataBaseDAO>(hotelRoomType);
            delete hotelRoomType;
            break;
        }
        case Tables::TPlaceArrival: {
            PlaceArrival *placeArrival = _getValuesFromDialog<PlaceArrival>(window);
            _addInDataBase<PlaceArrival, PlaceArrivalDataBaseDAO>(placeArrival);
            delete placeArrival;
            break;
        }
        case Tables::TPlaceArrivalType: {
            PlaceArrivalType *placeArrivalType = _getValuesFromDialog<PlaceArrivalType>(window);
            _addInDataBase<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>(placeArrivalType);
            delete placeArrivalType;
            break;
        }
        case Tables::TReservation: {
            Reservation *reservation = _getValuesFromDialog<Reservation>(window);
            _addInDataBase<Reservation, ReservationDataBaseDAO>(reservation);
            delete reservation;
            break;
        }
        case Tables::TReservByAgreement: {
            ReservByAgreement *reservByAgreement = _getValuesFromDialog<ReservByAgreement>(window);
            _addInDataBase<ReservByAgreement, ReservByAgreementDataBaseDAO>(reservByAgreement);
            delete reservByAgreement;
            break;
        }
        case Tables::TSight: {
            Sight *sight = _getValuesFromDialog<Sight>(window);
            _addInDataBase<Sight, SightDataBaseDAO>(sight);
            delete sight;
            break;
        }
        case Tables::TStatus: {
            Status *status = _getValuesFromDialog<Status>(window);
            _addInDataBase<Status, StatusDataBaseDAO>(status);
            delete status;
            break;
        }
        case Tables::TTicket: {
            Ticket *ticket = _getValuesFromDialog<Ticket>(window);
            _addInDataBase<Ticket, TicketDataBaseDAO>(ticket);
            delete ticket;
            break;
        }
        case Tables::TTour: {
            Tour *tour = _getValuesFromDialog<Tour>(window);
            _addInDataBase<Tour, TourDataBaseDAO>(tour);
            delete tour;
            break;
        }
        case Tables::TTourType: {
            TourType *tourType = _getValuesFromDialog<TourType>(window);
            _addInDataBase<TourType, TourTypeDataBaseDAO>(tourType);
            delete tourType;
            break;
        }
        case Tables::TTransportNode: {
            TransportNode *transportNode = _getValuesFromDialog<TransportNode>(window);
            _addInDataBase<TransportNode, TransportNodeDataBaseDAO>(transportNode);
            delete transportNode;
            break;
        }
        case Tables::TTransportNodeType: {
            TransportNodeType *transportNodeType = _getValuesFromDialog<TransportNodeType>(window);
            _addInDataBase<TransportNodeType, TransportNodeTypeDataBaseDAO>(transportNodeType);
            delete transportNodeType;
            break;
        }
    }
    renderTable(this->currentTable);
}
