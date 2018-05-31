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
#include "MainWindow.h"


AddWindow::AddWindow(QWidget *parent, const Qt::WindowFlags &f, Tables table) : QDialog(parent, f) {
    this->currentTable = table;
    this->formLayout = new QFormLayout();

    initDialogForm();

    this->okButton = new QPushButton("OK");
    this->cancelButton = new QPushButton("Cancel");

    if (this->currentTable == Tables::TReservation) {
        connect(this->okButton, SIGNAL(clicked()), this, SLOT(acceptForReservation()));
    }else{
        connect(this->okButton, SIGNAL(clicked()), this, SLOT(accept()));
    }

    connect(this->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    this->formLayout->addRow(this->okButton, this->cancelButton);

    this->setModal(true);
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

            foreach(QWidget *widget, this->editList) {
            delete widget;
        }
            foreach(QLabel *label, this->labelList) {
            delete label;
        }
}

QComboBox *AddWindow::initForeignEditLine(const QString columnName) {
    if (columnName.compare("City", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<City, CityDataBaseDAO>(columnName);
    } else if (columnName.compare("City Type", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<CityType, CityTypeDataBaseDAO>(columnName);
    } else if (columnName.compare("Client", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Client, ClientDataBaseDAO>(columnName);
    } else if (columnName.compare("Client rest", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<ClientRest, ClientRestDataBaseDAO>(columnName);
    } else if (columnName.compare("Contract", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Contract, ContractDataBaseDAO>(columnName);
    } else if (columnName.compare("Country", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Country, CountryDataBaseDAO>(columnName);
    } else if (columnName.compare("Documents", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Documents, DocumentsDataBaseDAO>(columnName);
    } else if (columnName.compare("Documents for tour", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<DocumentsForTour, DocumentsForTourDataBaseDAO>(columnName);
    } else if (columnName.compare("Flight", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Flight, FlightDataBaseDAO>(columnName);
    } else if (columnName.compare("Hotel", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Hotel, HotelDataBaseDAO>(columnName);
    } else if (columnName.compare("Hotel room", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<HotelRoom, HotelRoomDataBaseDAO>(columnName);
    } else if (columnName.compare("Hotel room type", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<HotelRoomType, HotelRoomTypeDataBaseDAO>(columnName);
    } else if (columnName.compare("Place arrival", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<PlaceArrival, PlaceArrivalDataBaseDAO>(columnName);
    } else if (columnName.compare("Place arrival type", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<PlaceArrivalType, PlaceArrivalTypeDataBaseDAO>(columnName);
    } else if (columnName.compare("Reservation", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Reservation, ReservationDataBaseDAO>(columnName);
    } else if (columnName.compare("Reservation by agreement", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<ReservByAgreement, ReservByAgreementDataBaseDAO>(columnName);
    } else if (columnName.compare("Sight", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Sight, SightDataBaseDAO>(columnName);
    } else if (columnName.compare("Ticket", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Ticket, TicketDataBaseDAO>(columnName);
    } else if (columnName.compare("Tour", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Tour, TourDataBaseDAO>(columnName);
    } else if (columnName.compare("Tour Type", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<TourType, TourTypeDataBaseDAO>(columnName);
    } else if (columnName.compare("Transport node", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<TransportNode, TransportNodeDataBaseDAO>(columnName);
    } else if (columnName.compare("Transport node type", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<TransportNodeType, TransportNodeTypeDataBaseDAO>(columnName);
    } else if (columnName.compare("Status", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<Status, StatusDataBaseDAO>(columnName);
    } else if (columnName.compare("Document Type", Qt::CaseInsensitive) == 0) {
        return _initForeignEditLine<DocumentType, DocumentTypeDataBaseDAO>(columnName);
    }
    return nullptr;
}

void AddWindow::acceptForReservation() {
    QStringList valuesFromDialog;
    valuesFromDialog << QString("0");
    for (int i = 0; i < this->editList.size(); i++) {
        QWidget *widget = this->editList[i];
        QString typeName(widget->metaObject()->className());
        if (typeName == "QLineEdit") {
            valuesFromDialog << dynamic_cast<QLineEdit *>(widget)->text();
        } else if (typeName == "QComboBox") {
            valuesFromDialog << QString(dynamic_cast<QComboBox *>(widget)->currentText().split(" ")[0]);
        } else if (typeName == "QDateEdit") {
            valuesFromDialog << dynamic_cast<QDateEdit *>(widget)->date().toString("dd.MM.yyyy");
        }
    }
    Reservation *model=new Reservation(valuesFromDialog);
    if(!ReservationDataBaseDAO().isBusy(model)){
        delete model;
        model= nullptr;
        accept();
    }else{
        QMessageBox *msg = new QMessageBox(QMessageBox::Information, "Warning", "This hotel room is busy in this date interval!", QMessageBox::Ok);
        msg->setModal(true);
        msg->exec();
        delete msg;
    }
    if(model!=nullptr){
        delete model;
        model=nullptr;
    }
}



