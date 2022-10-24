#include "mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTableView>
#include <iostream>
#include <sstream>
#include <string>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createTable();
    proxyModel = new ProxyModel();
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::createTable()
{
    model = new QStandardItemModel(0, 11, this);  // 1
    model->setHorizontalHeaderItem(0,
                                   new QStandardItem("Happiness Rank"));  // 2
    model->setHorizontalHeaderItem(1, new QStandardItem("Country"));      // 3
    model->setHorizontalHeaderItem(2, new QStandardItem("Region"));       // 4
    model->setHorizontalHeaderItem(3,
                                   new QStandardItem("Happiness Score"));  // 5
    model->setHorizontalHeaderItem(4, new QStandardItem("Family"));        // 6
    model->setHorizontalHeaderItem(5, new QStandardItem("Health"));        // 7
    model->setHorizontalHeaderItem(6, new QStandardItem("Freedom"));       // 8
    model->setHorizontalHeaderItem(7, new QStandardItem("GDP"));           // 9
    model->setHorizontalHeaderItem(8, new QStandardItem("Trust"));         // 10
    model->setHorizontalHeaderItem(9, new QStandardItem("Generosity"));    // 11
    model->setHorizontalHeaderItem(10, new QStandardItem("Year"));         // 12

    QString fileName = QString::fromStdString(
        "Happiness_Report1.csv");  // insert the .csv file!!!
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    file.readLine();
    while (!file.atEnd())
    {
        std::string token;
        std::string line = file.readLine().toStdString();
        std::cout << line << std::endl;
        std::istringstream ss(line);
        std::vector<std::string> lineAsVector;
        while (std::getline(ss, token, ','))
            lineAsVector.push_back(
                token);  // insert all words of this line in a vector
        HappinessReport h;
        h.happinessRank = stoi(lineAsVector[1]);
        h.country = lineAsVector[2];
        h.region = lineAsVector[3];
        h.happinessScore = stod(lineAsVector[4]);
        h.gdp = stod(lineAsVector[5]);
        h.socialSupport = stod(lineAsVector[6]);
        h.lifeexpectancy = stod(lineAsVector[7]);
        h.freedom = stod(lineAsVector[8]);
        h.trust = stod(lineAsVector[9]);
        h.generosity = stod(lineAsVector[10]);
        h.year = stoi(lineAsVector[11]);
        vec.push_back(h);
    }
    file.close();
    for (int i = 0; i < vec.size(); ++i)
    {
        model->insertRows(i, 1);
        model->setData(model->index(i, 0), vec[i].happinessRank);
        model->setData(model->index(i, 1),
                       QString::fromStdString(vec[i].country));
        model->setData(model->index(i, 2),
                       QString::fromStdString(vec[i].region));
        model->setData(model->index(i, 3), vec[i].happinessScore);
        model->setData(model->index(i, 4), vec[i].gdp);
        model->setData(model->index(i, 5), vec[i].socialSupport);
        model->setData(model->index(i, 6), vec[i].lifeexpectancy);
        model->setData(model->index(i, 7), vec[i].freedom);
        model->setData(model->index(i, 8), vec[i].trust);
        model->setData(model->index(i, 9), vec[i].generosity);
        model->setData(model->index(i, 10), vec[i].year);
    }
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_clicked()
{
    AddWind addWind;
    addWind.setPointers(model);
    addWind.setModal(true);
    addWind.exec();
}

void MainWindow::on_delete_2_clicked()
{
    int selectedRow = ui->tableView->currentIndex().row();
    model->removeRows(selectedRow, 1);
}

void MainWindow::on_deleteall_clicked()
{
    int row = model->rowCount();
    model->removeRows(0, row);
}

void MainWindow::on_save_clicked()
{
    QString filename =
        QFileDialog::getSaveFileName(this, "Save file", "", ".csv");
    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    for (int i = 0; i < model->rowCount(); i++)
    {
        std::string column0 =
            model->data(model->index(i, 0)).toString().toStdString();
        std::string column1 =
            model->data(model->index(i, 1)).toString().toStdString();
        std::string column2 =
            model->data(model->index(i, 2)).toString().toStdString();
        std::string column3 =
            model->data(model->index(i, 3)).toString().toStdString();
        std::string column4 =
            model->data(model->index(i, 4)).toString().toStdString();
        std::string column5 =
            model->data(model->index(i, 5)).toString().toStdString();
        std::string column6 =
            model->data(model->index(i, 6)).toString().toStdString();
        std::string column7 =
            model->data(model->index(i, 7)).toString().toStdString();
        std::string column8 =
            model->data(model->index(i, 8)).toString().toStdString();
        std::string column9 =
            model->data(model->index(i, 9)).toString().toStdString();
        std::string column10 =
            model->data(model->index(i, 10)).toString().toStdString();

        std::stringstream ss;
        ss << column0 << "," << column1 << "," << column2 << "," << column3
           << "," << column4 << "," << column5 << "," << column6 << ","
           << column7 << "," << column8 << "," << column9 << "," << column10
           << "," << '\n';

        f.write(ss.str().c_str());
    }
    f.close();
}

void MainWindow::on_filter_clicked()
{
    proxyModel->set_country(ui->lineEdit->text());
    proxyModel->set_region(ui->lineEdit_2->text());
    if (ui->lineEdit_3->text().trimmed().isEmpty())
        proxyModel->set_happinessRank(0);
    else
        proxyModel->set_happinessRank(ui->lineEdit_3->text().toInt());
}
