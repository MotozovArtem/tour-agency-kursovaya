#include <QtWidgets>
#include <models/Hotel.h>
#include <models/interfaces/dao_realization/HotelDataBaseDAO.h>
#include "SQL/SQLConnection.h"
#include "GUI/MainWindow.h"
#include "utils/Logger.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    SQLConnection *con = new SQLConnection("tour_agency", "rienel", "1957");
    QSqlDatabase db = con->getConnection();
    if (!db.open()) {
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "Warning",
                                              "Can't connect to database.<br> Exit program", QMessageBox::Ok);
        msgBox->exec();
        delete msgBox;
        return -1;
    }

//    QTableWidget *view = window->getPTable();

//    QList<Hotel *> hotelList = HotelDataBaseDAO().getAll();
//
//    view->setRowCount(hotelList.size());
//    view->setColumnCount(Hotel::columnList.length());
//
//    view->setHorizontalHeaderLabels(Hotel::columnList);
//    int i = 0;
//            foreach(Hotel *hotel, hotelList) {
//            view->setItem(i, 0, new QTableWidgetItem(QString::number(hotel->getId())));
//            view->setItem(i, 1, new QTableWidgetItem(*hotel->getHotelName()));
//            view->setItem(i, 2, new QTableWidgetItem(*hotel->getAddress()));
//            view->setItem(i, 3, new QTableWidgetItem(QString::number(hotel->getStars())));
//            view->setItem(i, 4, new QTableWidgetItem(hotel->getYearOfFoundation()->toString()));
//            view->setItem(i, 5, new QTableWidgetItem(QString::number(hotel->getIdCity())));
//        }
    window->renderTable<Hotel, HotelDataBaseDAO>();

    window->show();
    int exit_code = QApplication::exec();

    delete window;
    delete con;

    return exit_code;
}
