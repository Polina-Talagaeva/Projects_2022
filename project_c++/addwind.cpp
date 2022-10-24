#include "addwind.h"

#include "ui_addwind.h"

AddWind::AddWind(QWidget *parent) : QDialog(parent), ui(new Ui::AddWind)
{
    ui->setupUi(this);
}

AddWind::~AddWind() { delete ui; }
void AddWind::setPointers(QStandardItemModel *model) { this->model = model; }

void AddWind::on_pushButton_clicked()
{
    // update model
    int row = model->rowCount();  // get # of rows
    model->insertRows(row, 1);

    QModelIndex index = model->index(row, 0, QModelIndex());
    model->setData(index, ui->happinessRank->text());
    QModelIndex index1 = model->index(row, 1, QModelIndex());
    model->setData(index1, ui->country->text());
    QModelIndex index2 = model->index(row, 2, QModelIndex());
    model->setData(index2, ui->region->text());
    QModelIndex index3 = model->index(row, 3, QModelIndex());
    model->setData(index3, ui->happinessScore->text());
    QModelIndex index4 = model->index(row, 4, QModelIndex());
    model->setData(index4, ui->socialSupport->text());
    QModelIndex index5 = model->index(row, 5, QModelIndex());
    model->setData(index5, ui->lifeexpectancy->text());
    QModelIndex index6 = model->index(row, 6, QModelIndex());
    model->setData(index6, ui->freedom->text());
    QModelIndex index7 = model->index(row, 7, QModelIndex());
    model->setData(index7, ui->gdp->text());
    QModelIndex index8 = model->index(row, 8, QModelIndex());
    model->setData(index4, ui->trust->text());
    QModelIndex index9 = model->index(row, 9, QModelIndex());
    model->setData(index9, ui->generosity->text());
    QModelIndex index10 = model->index(row, 10, QModelIndex());
    model->setData(index10, ui->year->text());

    this->close();
}
