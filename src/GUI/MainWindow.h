//
// Created by rienel on 04.05.18.
//

#ifndef PSQLWORK_MAINWINDOW_H
#define PSQLWORK_MAINWINDOW_H

#include <QtCore>
#include <QtWidgets>
#include <models/interfaces/ModelDAO.h>

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    QTableWidget *pTable;
    QPushButton *pButton;
    QTabWidget *tabWidget;
    QMenuBar *menu;
public:
    enum Tables {
        TCity = 0,
        TCityType,
        TClient,
        TClientRest,
        TContract,
        TCountry,
        TDocuments,
        TDocumentsForTour,
        TDocumentsType,
        TFlight,
        THotel,
        THotelRoom,
        THotelRoomType,
        TPlaceArrival,
        TPlaceArrivalType,
        TReservation,
        TReservByAgreement,
        TSight,
        TStatus,
        TTicket,
        TTour,
        TTourType,
        TTransportNode,
        TTransportNodeType
    };

    MainWindow(QMainWindow *pwgt = 0);

    virtual ~MainWindow();

    QTableWidget *getPTable() const;

    void setPTable(QTableWidget *pTable);

    QPushButton *getPButton() const;

    void setPButton(QPushButton *pButton);

    QTabWidget *getTabWidget() const;

    void setTabWidget(QTabWidget *tabWidget);

    template<class modelClass, class daoClass>
    void _renderTable() {
        QList<modelClass *> objectList = daoClass().getAllFilled();
        this->pTable->setRowCount(objectList.size());
        this->pTable->setColumnCount(modelClass::columnList.length());

        this->pTable->setHorizontalHeaderLabels(modelClass::columnList);
        int i = 0;
                foreach(modelClass *model, objectList) {
                int j = 0;
                QStringListIterator iterator(*model->getValueList());
                while (iterator.hasNext()) {
                    this->pTable->setItem(i, j, new QTableWidgetItem(iterator.next()));
                    j++;
                }
                i++;
            }
    };

public slots:

    void renderTable(Tables tables);


//    template<class modelClass, class daoClass>
//    void renderTable();
};


#endif //PSQLWORK_MAINWINDOW_H
