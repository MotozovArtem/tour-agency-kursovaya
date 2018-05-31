#include <QtWidgets>
#include <models/Hotel.h>
#include <models/interfaces/dao_realization/HotelDataBaseDAO.h>
#include "SQL/SQLConnection.h"
#include "GUI/MainWindow.h"
#include "utils/Logger.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);

    SQLConnection *con = new SQLConnection("tour_agency", "rienel", "1957");
    QSqlDatabase db = con->getConnection();

    MainWindow *window = new MainWindow();
    if (!db.open()) {
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "Warning",
                                              "Can't connect to database.<br> Exit program", QMessageBox::Ok);
        msgBox->exec();
        delete msgBox;
        return -1;
    }
    window->renderTable(Tables::TCity);
    window->show();
    int exit_code = QApplication::exec();

    delete window;
    delete con;

    return exit_code;
}
