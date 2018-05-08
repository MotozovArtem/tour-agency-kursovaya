//#include <libpq-fe.h>
//#include <cstdio>
//#include <cstdlib>
//
//#define UNUSED(x) (void)(x)
//
//PGconn *dbConnection = nullptr;
//PGresult *res = nullptr;
//
//static void terminate(int code) {
//    if (code != 0) {
//        fprintf(stderr, "%s\n", PQerrorMessage(dbConnection));
//    }
//
//    if (res != nullptr) {
//        PQclear(res);
//    }
//
//    if (dbConnection != nullptr) {
//        PQfinish(dbConnection);
//    }
//
//    exit(code);
//}
//
//static void clearRes() {
//    PQclear(res);
//    res = nullptr;
//}
//
//static void processNotice(void *arg, const char *message) {
//    UNUSED(arg);
//    UNUSED(message);
//}
//
//int main() {
//
//
//    int libpq_ver = PQlibVersion();
//    printf("Version of libpq: %d\n", libpq_ver);
//
//    dbConnection = PQconnectdb("user=rienel password=1957 host=127.0.0.1 dbname=testdb");
//    if (PQstatus(dbConnection) != CONNECTION_OK) {
//        terminate(1);
//    }
//
//    PQsetNoticeProcessor(dbConnection, processNotice, nullptr);
//
//    int server_ver = PQserverVersion(dbConnection);
//    char *user = PQuser(dbConnection);
//    char *db_name = PQdb(dbConnection);
//
//    printf("Server version: %d\n", server_ver);
//    printf("User: %s\n", user);
//    printf("DB name: %s\n", db_name);
//
//    res = PQexec(dbConnection, "SELECT * FROM students");
//    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
//        terminate(1);
//    }
//
//    int ncols = PQnfields(res);
//    printf("In \"student\" table have %d columns", ncols);
//    for (int i = 0; i < ncols; i++) {
//        char *name = PQfname(res, i);
//        printf(" %s", name);
//    }
//    printf("\n");
//
//    int nrows = PQntuples(res);
//    for (int i = 0; i < nrows; i++) {
//        char *stud_id = PQgetvalue(res, i, 0);
//        char *first_name = PQgetvalue(res, i, 1);
//        char *name = PQgetvalue(res, i, 2);
//        printf("Id: %s, first_name: %s, name: %s", stud_id, first_name, name);
//    }
//    printf("Total: %d rows\n", nrows);
//
//    clearRes();
//    terminate(0);
//    return 0;
//}

#include <QtWidgets>
#include <models/Hotel.h>
#include <models/interfaces/dao_realization/HotelDataBaseDAO.h>
#include "SQL/SQLConnection.h"
#include "GUI/MainWindow.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    SQLConnection *con = new SQLConnection("tour_agency", "rienel", "1957");
    QSqlDatabase db = con->getConnection();

    if (!db.open()) {
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Warning, "Warning",
                                              "Can't connect to database.<br> Exit program", QMessageBox::Ok);
        msgBox->exec();
        delete msgBox;
        return -1;
    }

    QTableWidget *view = window->getPTable();
    QPushButton *button = window->getPButton();


    QList<Hotel *> hotelList = HotelDataBaseDAO().getAll();

    view->setRowCount(hotelList.size());
    view->setColumnCount(6);
    int i = 0;
            foreach(Hotel *hotel, hotelList) {
            view->setItem(i, 0, new QTableWidgetItem(QString::number(hotel->getId())));
            view->setItem(i, 1, new QTableWidgetItem(*hotel->getHotelName()));
            view->setItem(i, 2, new QTableWidgetItem(*hotel->getAddress()));
            view->setItem(i, 3, new QTableWidgetItem(QString::number(hotel->getStars())));
            view->setItem(i, 4, new QTableWidgetItem(hotel->getYearOfFoundation()->toString()));
            view->setItem(i, 5, new QTableWidgetItem(QString::number(hotel->getIdCity())));
        }



//    QTabWidget *tabWidget = window->getTabWidget();
//    QStringList tableList = db.tables();
//
//
//    QSqlRelationalTableModel model;
//    model.setTable("Hotel");
//    model.setRelation(5, QSqlRelation("City", "id", "name"));
//
//    model.select();
//    model.setEditStrategy(QSqlTableModel::OnManualSubmit);
//
//    QObject::connect(button, SIGNAL(button->clicked()), &model, SLOT(model.submitAll()));
//
//    view->setModel(&model);
//    view->setItemDelegate(new QSqlRelationalDelegate(view));
//
//            foreach(QString label, tableList) {
//            tabWidget->addTab(new QLabel(label, tabWidget), label); // На каждую страницу добавляет Label
//        }


    window->show();
    int exit_code = app.exec();
//
    delete window;
    delete con;

    return exit_code;
}
