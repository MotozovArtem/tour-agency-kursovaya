//
// Created by rienel on 27.05.18.
//

#include "TicketDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<Ticket *> TicketDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Ticket *> list;
    if (query.exec("SELECT id, place, date_flight, "
                   "price, date_of_purchase, id_documents, id_flight FROM Ticket ORDER BY id")) {
        while (query.next()) {
            list << new Ticket(
                    query.value("id").toInt(),
                    query.value("place").toInt(),
                    query.value("date_flight").toDate(),
                    query.value("price").toFloat(),
                    query.value("date_of_purchase").toDate(),
                    query.value("id_documents").toInt(),
                    query.value("id_flight").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TicketDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Ticket *TicketDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT Ticket.id, Ticket.place, Ticket.date_flight, Ticket.price, Ticket.date_of_purchase, Ticket.id_documents, Ticket.id_flight,  "
                  "Documents.document_serial "
                  "FROM Ticket "
                  "LEFT JOIN Documents ON (Ticket.id_documents=Documents.id) "
                  "WHERE Ticket.id=:id");
    query.bindValue(":id", id);
    Ticket *ticket = nullptr;
    if (query.exec()) {
        while (query.next()) {
            ticket = new Ticket(
                    query.value("id").toInt(),
                    query.value("place").toInt(),
                    query.value("date_flight").toDate(),
                    query.value("price").toFloat(),
                    query.value("date_of_purchase").toDate(),
                    query.value("id_documents").toInt(),
                    query.value("id_flight").toInt()
            );
            ticket->setFlight(new QString(query.value("id_flight").toString()));
            ticket->setDocuments(new QString(query.value("document_serial").toString()));
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TicketDataBaseDAO::getById() error", query.lastError().text()));
    }
    return ticket;
}

void TicketDataBaseDAO::add(Ticket *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Ticket(place, date_flight, price, date_of_purchase, id_documents, id_flight) "
                  "VALUES (:place, :date_flight, :price, :date_of_purchase, :id_documents, :id_flight)");
    query.bindValue(":place", model->getPlace());
    query.bindValue(":date_flight", *model->getDateFlight());
    query.bindValue(":price", model->getPrice());
    query.bindValue(":date_of_purchase", *model->getDateOfPurchase());
    query.bindValue(":id_documents", model->getIdDocuments());
    query.bindValue(":id_flight", model->getIdFlight());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TicketDataBaseDAO::add() error", query.lastError().text()));
    }
}

void TicketDataBaseDAO::update(Ticket *model) {
    QSqlQuery query;
    query.prepare("UPDATE Ticket SET place=:place, date_flight=:date_flight, "
                  "price=:price, date_of_purchase=:date_of_purchase, id_documents=:id_documents, id_flight=:id_flight"
                  " WHERE id=:id");
    query.bindValue(":place", model->getPlace());
    query.bindValue(":date_flight", *model->getDateFlight());
    query.bindValue(":price", model->getPrice());
    query.bindValue(":date_of_purchase", *model->getDateOfPurchase());
    query.bindValue(":id_documents", model->getIdDocuments());
    query.bindValue(":id_flight", model->getIdFlight());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TicketDataBaseDAO::update() error", query.lastError().text()));
    }
}

void TicketDataBaseDAO::del(Ticket *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Ticket WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TicketDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Ticket *> TicketDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<Ticket *> list;
    if (query.exec("SELECT Ticket.id, Ticket.place, Ticket.date_flight, Ticket.price, Ticket.date_of_purchase, "
                   "Ticket.id_documents, Ticket.id_flight, "
                   "Documents.document_serial, Ticket.id_flight FROM Ticket "
                   "LEFT JOIN Documents ON (Ticket.id_documents=Documents.id)"
                   "ORDER BY id")) {
        while (query.next()) {
            Ticket *ticket = new Ticket(
                    query.value("id").toInt(),
                    query.value("place").toInt(),
                    query.value("date_flight").toDate(),
                    query.value("price").toFloat(),
                    query.value("date_of_purchase").toDate(),
                    query.value("id_documents").toInt(),
                    query.value("id_flight").toInt()
            );
            ticket->setDocuments(new QString(query.value("city_name").toString()));
            ticket->setFlight(new QString(query.value("id_flight").toString()));
            list << ticket;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TicketDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}

