//
// Created by rienel on 16.04.18.
//

#include "HotelDataBaseDAO.h"
#include <QtSql/QtSql>
#include "SQL/SQLConnection.h"

//#include <QtSql/QtSql>
//#include "iostream"
//
//int main() {
//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//    db.setDatabaseName("testdb");
//    db.setUserName("rienel");
//    db.setHostName("asus");
//    db.setPassword("1957");
//    if (!db.open()) {
//        qDebug() << "Cannot open database: " << db.lastError();
//        return 0;
//    }
//    QStringList lst = db.tables();
//            foreach(QString str, lst) {
//            std::cout << "Table:" << str.toStdString();
//        }
//    return 0;
//}


QList<Hotel *> HotelDataBaseDAO::getAll() {
//    SQLConnection *con = new SQLConnection("tour_agency", "rienel", "1957");
//    QSqlDatabase db = con->getConnection();
//    if (!db.open()) {
//        qDebug() << "Ошибка"; // TODO: Запихнуть сюда логгер кастомный
//    }
    QSqlQuery query;
    query.exec("SELECT * FROM Hotel");
    QSqlRecord rec = query.record();
    QList<Hotel *> hotelList;
    while (query.next()) {
        hotelList << new Hotel(
                query.value(rec.indexOf("id")).toInt(),
                query.value(rec.indexOf("hotel_name")).toString(),
                query.value(rec.indexOf("address")).toString(),
                query.value(rec.indexOf("stars")).toInt(),
                query.value(rec.indexOf("year_of_foundation")).toDate(),
                query.value(rec.indexOf("id_city")).toInt()
        );
    }
//    delete con;
    return hotelList;
}

Hotel *HotelDataBaseDAO::getById(int id) {
    return nullptr;
}

void HotelDataBaseDAO::add(Hotel *model) {

}

void HotelDataBaseDAO::update(Hotel *model) {

}

void HotelDataBaseDAO::del(Hotel *model) {

}
