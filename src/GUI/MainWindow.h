//
// Created by rienel on 04.05.18.
//

#ifndef PSQLWORK_MAINWINDOW_H
#define PSQLWORK_MAINWINDOW_H

#include <QtCore>
#include <QtWidgets>

class MainWindow : public QWidget {
Q_OBJECT
private:
    QVBoxLayout *pLayout;
    QTableWidget *pTable;
    QPushButton *pButton;
    QTabWidget *tabWidget;
public:
    QTabWidget *getTabWidget() const;

    void setTabWidget(QTabWidget *tabWidget);

public:
    MainWindow(QWidget *pwgt = nullptr);

    ~MainWindow();

    QVBoxLayout *getPLayout() const;

    void setPLayout(QVBoxLayout *pLayout);

    QTableWidget *getPTable() const;

    void setPTable(QTableWidget *pTable);

    QPushButton *getPButton() const;

    void setPButton(QPushButton *pButton);
};


#endif //PSQLWORK_MAINWINDOW_H
