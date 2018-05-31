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

    QMenu *about = new QMenu("&About");
    menu->addMenu(about);

    QAction *aboutAction = new QAction("&About");
    about->addAction(aboutAction);

    connect(this->rightMenu, SIGNAL(change(Tables)), this, SLOT(renderTable(Tables)));

    this->resize(600, 400);

    QRect frame = this->frameGeometry();
    QPoint center = QDesktopWidget().availableGeometry().center();
    frame.moveCenter(center);
    this->move(frame.topLeft());


    this->setMenuBar(menu);
    this->setCentralWidget(this->mainWidget);
}

QTableWidget *MainWindow::getPTable() const {
    return pTable;
}

void MainWindow::setPTable(QTableWidget *pTable) {
    MainWindow::pTable = pTable;
}


MainWindow::~MainWindow() {
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
        case Tables::TCity: {
            _renderTable<City, CityDataBaseDAO>();
            this->setWindowTitle("City");
            break;
        }
        case Tables::TCityType: {
            _renderTable<CityType, CityTypeDataBaseDAO>();
            this->setWindowTitle("City Type");
            break;
        }
        case Tables::TClient: {
            _renderTable<Client, ClientDataBaseDAO>();
            this->setWindowTitle("Client");
            break;
        }
        case Tables::TClientRest: {
            _renderTable<ClientRest, ClientRestDataBaseDAO>();
            this->setWindowTitle("Client Rest");
            break;
        }
        case Tables::TContract: {
            _renderTable<Contract, ContractDataBaseDAO>();
            this->setWindowTitle("Contract");
            break;
        }
        case Tables::TCountry: {
            _renderTable<Country, CountryDataBaseDAO>();
            this->setWindowTitle("Country");
            break;
        }
        case Tables::TDocuments: {
            _renderTable<Documents, DocumentsDataBaseDAO>();
            this->setWindowTitle("Documents");
            break;
        }
        case Tables::TDocumentsForTour: {
            _renderTable<DocumentsForTour, DocumentsForTourDataBaseDAO>();
            this->setWindowTitle("Documents for Tour");
            break;
        }
        case Tables::TDocumentsType: {
            _renderTable<DocumentType, DocumentTypeDataBaseDAO>();
            this->setWindowTitle("Document type");
            break;
        }
        case Tables::TFlight: {
            _renderTable<Flight, FlightDataBaseDAO>();
            this->setWindowTitle("Flight");
            break;
        }
        case Tables::THotel: {
            _renderTable<Hotel, HotelDataBaseDAO>();
            this->setWindowTitle("Hotel");
            break;
        }
        case Tables::THotelRoom: {
            _renderTable<HotelRoom, HotelRoomDataBaseDAO>();
            this->setWindowTitle("Hotel Room");
            break;
        }
        case Tables::THotelRoomType: {
            _renderTable<HotelRoomType, HotelRoomTypeDataBaseDAO>();
            this->setWindowTitle("Hotell Room Type");
            break;
        }
        case Tables::TPlaceArrival: {
            _renderTable<PlaceArrival, PlaceArrivalDataBaseDAO>();
            this->setWindowTitle("Place Arrival");
            break;
        }
        case Tables::TPlaceArrivalType: {
            _renderTable<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>();
            this->setWindowTitle("Place Arrival Type");
            break;
        }
        case Tables::TReservation: {
            _renderTable<Reservation, ReservationDataBaseDAO>();
            this->setWindowTitle("Reservation");
            break;
        }
        case Tables::TReservByAgreement: {
            _renderTable<ReservByAgreement, ReservByAgreementDataBaseDAO>();
            this->setWindowTitle("Reservation by Agreement");
            break;
        }
        case Tables::TSight: {
            _renderTable<Sight, SightDataBaseDAO>();
            this->setWindowTitle("Sight");
            break;
        }
        case Tables::TStatus: {
            _renderTable<Status, StatusDataBaseDAO>();
            this->setWindowTitle("Status");
            break;
        }
        case Tables::TTicket: {
            _renderTable<Ticket, TicketDataBaseDAO>();
            this->setWindowTitle("Ticket");
            break;
        }
        case Tables::TTour: {
            _renderTable<Tour, TourDataBaseDAO>();
            this->setWindowTitle("Tour");
            break;
        }
        case Tables::TTourType: {
            _renderTable<TourType, TourTypeDataBaseDAO>();
            this->setWindowTitle("Tour type");
            break;
        }
        case Tables::TTransportNode: {
            _renderTable<TransportNode, TransportNodeDataBaseDAO>();
            this->setWindowTitle("Transport node");
            break;
        }
        case Tables::TTransportNodeType: {
            _renderTable<TransportNodeType, TransportNodeTypeDataBaseDAO>();
            this->setWindowTitle("Transport node type");
            break;
        }
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
    AddWindow *addWindow = new AddWindow(this, Qt::Window | Qt::WindowSystemMenuHint, this->currentTable);
    addWindow->setModal(true);
    int exit_code = addWindow->exec();
    if (exit_code == QDialog::Accepted) {
        getValuesFromDialog(addWindow);
    } else {
        std::cout << "REJECTED\n";
    }
    delete addWindow;
}

void MainWindow::editRow() {
    int curRow = this->pTable->currentRow();
//    QMessageBox *msg = new QMessageBox(QMessageBox::Information, "MSG", QString::number(curRow));
//    msg->exec();
//    delete msg;
    if(curRow!=-1){
        int idRow = this->pTable->item(curRow, 0)->text().toInt();
        EditWindow *editWindow = new EditWindow(this, Qt::Window | Qt::WindowSystemMenuHint, this->currentTable, idRow);
        editWindow->setModal(true);
        if (editWindow->exec() == QDialog::Accepted) {
            getValuesForEdit(editWindow, idRow);
        } else {
            std::cout << "REJECTED\n";
        }
        delete editWindow;
    }else{
        QMessageBox *msg = new QMessageBox(QMessageBox::Information, "Edit", "For editing select one row", QMessageBox::Ok);
        msg->setModal(true);
        msg->exec();
        delete msg;
    }



}

void MainWindow::deleteRow() {
    int curRow = this->pTable->currentRow();
    if(curRow!=-1){
        int idRow = this->pTable->item(curRow, 0)->text().toInt();
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Question, "Delete", "Do you want to delete this row?",
                                              QMessageBox::No | QMessageBox::Yes);
        msgBox->setModal(true);
        if (msgBox->exec() == QMessageBox::Yes) {
            switch (this->currentTable) {
                case Tables::TCity:
                    _deleteFromDataBase<City, CityDataBaseDAO>(idRow);
                    break;
                case Tables::TCityType:
                    _deleteFromDataBase<CityType, CityTypeDataBaseDAO>(idRow);
                    break;
                case Tables::TClient:
                    _deleteFromDataBase<Client, ClientDataBaseDAO>(idRow);
                    break;
                case Tables::TClientRest:
                    _deleteFromDataBase<ClientRest, ClientRestDataBaseDAO>(idRow);
                    break;
                case Tables::TContract:
                    _deleteFromDataBase<Contract, ContractDataBaseDAO>(idRow);
                    break;
                case Tables::TCountry:
                    _deleteFromDataBase<Country, CountryDataBaseDAO>(idRow);
                    break;
                case Tables::TDocuments:
                    _deleteFromDataBase<Documents, DocumentsDataBaseDAO>(idRow);
                    break;
                case Tables::TDocumentsForTour:
                    _deleteFromDataBase<DocumentsForTour, DocumentsForTourDataBaseDAO>(idRow);
                    break;
                case Tables::TDocumentsType:
                    _deleteFromDataBase<DocumentType, DocumentTypeDataBaseDAO>(idRow);
                    break;
                case Tables::TFlight:
                    _deleteFromDataBase<Flight, FlightDataBaseDAO>(idRow);
                    break;
                case Tables::THotel:
                    _deleteFromDataBase<Hotel, HotelDataBaseDAO>(idRow);
                    break;
                case Tables::THotelRoom:
                    _deleteFromDataBase<HotelRoom, HotelRoomDataBaseDAO>(idRow);
                    break;
                case Tables::THotelRoomType:
                    _deleteFromDataBase<HotelRoomType, HotelRoomTypeDataBaseDAO>(idRow);
                    break;
                case Tables::TPlaceArrival:
                    _deleteFromDataBase<PlaceArrival, PlaceArrivalDataBaseDAO>(idRow);
                    break;
                case Tables::TPlaceArrivalType:
                    _deleteFromDataBase<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>(idRow);
                    break;
                case Tables::TReservation:
                    _deleteFromDataBase<Reservation, ReservationDataBaseDAO>(idRow);
                    break;
                case Tables::TReservByAgreement:
                    _deleteFromDataBase<ReservByAgreement, ReservByAgreementDataBaseDAO>(idRow);
                    break;
                case Tables::TSight:
                    _deleteFromDataBase<Sight, SightDataBaseDAO>(idRow);
                    break;
                case Tables::TStatus:
                    _deleteFromDataBase<Status, StatusDataBaseDAO>(idRow);
                    break;
                case Tables::TTicket:
                    _deleteFromDataBase<Ticket, TicketDataBaseDAO>(idRow);
                    break;
                case Tables::TTour:
                    _deleteFromDataBase<Tour, TourDataBaseDAO>(idRow);
                    break;
                case Tables::TTourType:
                    _deleteFromDataBase<TourType, TourTypeDataBaseDAO>(idRow);
                    break;
                case Tables::TTransportNode:
                    _deleteFromDataBase<TransportNode, TransportNodeDataBaseDAO>(idRow);
                    break;
                case Tables::TTransportNodeType:
                    _deleteFromDataBase<TransportNodeType, TransportNodeTypeDataBaseDAO>(idRow);
                    break;
            }
        }
        delete msgBox;
        this->renderTable(this->currentTable);
    }else{
        QMessageBox *msg = new QMessageBox(QMessageBox::Information, "Delete", "For deleting select one row", QMessageBox::Ok);
        msg->setModal(true);
        msg->exec();
        delete msg;
    }
}

void MainWindow::getValuesFromDialog(AddWindow *window) {
    QList<QWidget *> editList = window->getEditList();
    switch (this->currentTable) {
        case Tables::TCity: {
            auto *city = _getValuesFromDialog<City>(window);
            _addInDataBase<City, CityDataBaseDAO>(city);
            delete city;
            break;
        }
        case Tables::TCityType: {
            auto *cityType = _getValuesFromDialog<CityType>(window);
            _addInDataBase<CityType, CityTypeDataBaseDAO>(cityType);
            delete cityType;
            break;
        }
        case Tables::TClient: {
            auto *client = _getValuesFromDialog<Client>(window);
            _addInDataBase<Client, ClientDataBaseDAO>(client);
            delete client;
            break;
        }
        case Tables::TClientRest: {
            auto *clientRest = _getValuesFromDialog<ClientRest>(window);
            _addInDataBase<ClientRest, ClientRestDataBaseDAO>(clientRest);
            delete clientRest;
            break;
        }
        case Tables::TContract: {
            auto *contract = _getValuesFromDialog<Contract>(window);
            _addInDataBase<Contract, ContractDataBaseDAO>(contract);
            delete contract;
            break;
        }
        case Tables::TCountry: {
            auto *country = _getValuesFromDialog<Country>(window);
            _addInDataBase<Country, CountryDataBaseDAO>(country);
            delete country;
            break;
        }
        case Tables::TDocuments: {
            auto *document = _getValuesFromDialog<Documents>(window);
            _addInDataBase<Documents, DocumentsDataBaseDAO>(document);
            delete document;
            break;
        }
        case Tables::TDocumentsForTour: {
            auto *documentsForTour = _getValuesFromDialog<DocumentsForTour>(window);
            _addInDataBase<DocumentsForTour, DocumentsForTourDataBaseDAO>(documentsForTour);
            delete documentsForTour;
            break;
        }
        case Tables::TDocumentsType: {
            auto *documentType = _getValuesFromDialog<DocumentType>(window);
            _addInDataBase<DocumentType, DocumentTypeDataBaseDAO>(documentType);
            delete documentType;
            break;
        }
        case Tables::TFlight: {
            auto *flight = _getValuesFromDialog<Flight>(window);
            _addInDataBase<Flight, FlightDataBaseDAO>(flight);
            delete flight;
            break;
        }
        case Tables::THotel: {
            auto *hotel = _getValuesFromDialog<Hotel>(window);
            _addInDataBase<Hotel, HotelDataBaseDAO>(hotel);
            delete hotel;
            break;
        }
        case Tables::THotelRoom: {
            auto *hotelRoom = _getValuesFromDialog<HotelRoom>(window);
            _addInDataBase<HotelRoom, HotelRoomDataBaseDAO>(hotelRoom);
            delete hotelRoom;
            break;
        }
        case Tables::THotelRoomType: {
            auto *hotelRoomType = _getValuesFromDialog<HotelRoomType>(window);
            _addInDataBase<HotelRoomType, HotelRoomTypeDataBaseDAO>(hotelRoomType);
            delete hotelRoomType;
            break;
        }
        case Tables::TPlaceArrival: {
            auto *placeArrival = _getValuesFromDialog<PlaceArrival>(window);
            _addInDataBase<PlaceArrival, PlaceArrivalDataBaseDAO>(placeArrival);
            delete placeArrival;
            break;
        }
        case Tables::TPlaceArrivalType: {
            auto *placeArrivalType = _getValuesFromDialog<PlaceArrivalType>(window);
            _addInDataBase<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>(placeArrivalType);
            delete placeArrivalType;
            break;
        }
        case Tables::TReservation: {
            auto *reservation = _getValuesFromDialog<Reservation>(window);
            _addInDataBase<Reservation, ReservationDataBaseDAO>(reservation);
            delete reservation;
            break;
        }
        case Tables::TReservByAgreement: {
            auto *reservByAgreement = _getValuesFromDialog<ReservByAgreement>(window);
            _addInDataBase<ReservByAgreement, ReservByAgreementDataBaseDAO>(reservByAgreement);
            delete reservByAgreement;
            break;
        }
        case Tables::TSight: {
            auto *sight = _getValuesFromDialog<Sight>(window);
            _addInDataBase<Sight, SightDataBaseDAO>(sight);
            delete sight;
            break;
        }
        case Tables::TStatus: {
            auto *status = _getValuesFromDialog<Status>(window);
            _addInDataBase<Status, StatusDataBaseDAO>(status);
            delete status;
            break;
        }
        case Tables::TTicket: {
            auto *ticket = _getValuesFromDialog<Ticket>(window);
            _addInDataBase<Ticket, TicketDataBaseDAO>(ticket);
            delete ticket;
            break;
        }
        case Tables::TTour: {
            auto *tour = _getValuesFromDialog<Tour>(window);
            _addInDataBase<Tour, TourDataBaseDAO>(tour);
            delete tour;
            break;
        }
        case Tables::TTourType: {
            auto *tourType = _getValuesFromDialog<TourType>(window);
            _addInDataBase<TourType, TourTypeDataBaseDAO>(tourType);
            delete tourType;
            break;
        }
        case Tables::TTransportNode: {
            auto *transportNode = _getValuesFromDialog<TransportNode>(window);
            _addInDataBase<TransportNode, TransportNodeDataBaseDAO>(transportNode);
            delete transportNode;
            break;
        }
        case Tables::TTransportNodeType: {
            auto *transportNodeType = _getValuesFromDialog<TransportNodeType>(window);
            _addInDataBase<TransportNodeType, TransportNodeTypeDataBaseDAO>(transportNodeType);
            delete transportNodeType;
            break;
        }
    }
    renderTable(this->currentTable);
}

void MainWindow::getValuesForEdit(EditWindow *window, int idRow) {
    QList<QWidget *> editList = window->getEditList();
    switch (this->currentTable) {
        case Tables::TCity: {
            auto *obj = _getValuesFromDialog<City>(window);
            obj->setId(idRow);
            _editInDataBase<City, CityDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TCityType: {
            auto *obj = _getValuesFromDialog<CityType>(window);
            obj->setId(idRow);
            _editInDataBase<CityType, CityTypeDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TClient: {
            auto *obj = _getValuesFromDialog<Client>(window);
            obj->setId(idRow);
            _editInDataBase<Client, ClientDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TClientRest: {
            auto *obj = _getValuesFromDialog<ClientRest>(window);
            obj->setId(idRow);
            _editInDataBase<ClientRest, ClientRestDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TContract: {
            auto *obj = _getValuesFromDialog<Contract>(window);
            obj->setId(idRow);
            _editInDataBase<Contract, ContractDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TCountry: {
            auto *obj = _getValuesFromDialog<Country>(window);
            obj->setId(idRow);
            _editInDataBase<Country, CountryDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TDocuments: {
            auto *obj = _getValuesFromDialog<Documents>(window);
            obj->setId(idRow);
            _editInDataBase<Documents, DocumentsDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TDocumentsForTour: {
            auto *obj = _getValuesFromDialog<DocumentsForTour>(window);
            obj->setId(idRow);
            _editInDataBase<DocumentsForTour, DocumentsForTourDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TDocumentsType: {
            auto *obj = _getValuesFromDialog<DocumentType>(window);
            obj->setId(idRow);
            _editInDataBase<DocumentType, DocumentTypeDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TFlight: {
            auto *obj = _getValuesFromDialog<Flight>(window);
            obj->setId(idRow);
            _editInDataBase<Flight, FlightDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::THotel: {
            auto *obj = _getValuesFromDialog<Hotel>(window);
            obj->setId(idRow);
            _editInDataBase<Hotel, HotelDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::THotelRoom: {
            auto *obj = _getValuesFromDialog<HotelRoom>(window);
            obj->setId(idRow);
            _editInDataBase<HotelRoom, HotelRoomDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::THotelRoomType: {
            auto *obj = _getValuesFromDialog<HotelRoomType>(window);
            obj->setId(idRow);
            _editInDataBase<HotelRoomType, HotelRoomTypeDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TPlaceArrival: {
            auto *obj = _getValuesFromDialog<PlaceArrival>(window);
            obj->setId(idRow);
            _editInDataBase<PlaceArrival, PlaceArrivalDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TPlaceArrivalType: {
            auto *obj = _getValuesFromDialog<PlaceArrivalType>(window);
            obj->setId(idRow);
            _editInDataBase<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TReservation: {
            auto *obj = _getValuesFromDialog<Reservation>(window);
            obj->setId(idRow);
            _editInDataBase<Reservation, ReservationDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TReservByAgreement: {
            auto *obj = _getValuesFromDialog<ReservByAgreement>(window);
            obj->setId(idRow);
            _editInDataBase<ReservByAgreement, ReservByAgreementDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TSight: {
            auto *obj = _getValuesFromDialog<Sight>(window);
            obj->setId(idRow);
            _editInDataBase<Sight, SightDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TStatus: {
            auto *obj = _getValuesFromDialog<Status>(window);
            obj->setId(idRow);
            _editInDataBase<Status, StatusDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TTicket: {
            auto *obj = _getValuesFromDialog<Ticket>(window);
            obj->setId(idRow);
            _editInDataBase<Ticket, TicketDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TTour: {
            auto *obj = _getValuesFromDialog<Tour>(window);
            obj->setId(idRow);
            _editInDataBase<Tour, TourDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TTourType: {
            auto *obj = _getValuesFromDialog<TourType>(window);
            obj->setId(idRow);
            _editInDataBase<TourType, TourTypeDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TTransportNode: {
            auto *obj = _getValuesFromDialog<TransportNode>(window);
            obj->setId(idRow);
            _editInDataBase<TransportNode, TransportNodeDataBaseDAO>(obj);
            delete obj;
            break;
        }
        case Tables::TTransportNodeType: {
            auto *obj = _getValuesFromDialog<TransportNodeType>(window);
            obj->setId(idRow);
            _editInDataBase<TransportNodeType, TransportNodeTypeDataBaseDAO>(obj);
            delete obj;
            break;
        }
    }
    renderTable(this->currentTable);
}
