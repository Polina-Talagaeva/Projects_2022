#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QString>
#include <QTableView>
#include <vector>

#include "HappinessReport.h"
#include "addwind.h"
#include "model.h"
#include "proxymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStandardItemModel *model;  // Table

   private slots:
    void createTable();
    void on_pushButton_clicked();
    void on_delete_2_clicked();
    void on_deleteall_clicked();
    void on_save_clicked();
    void on_filter_clicked();

   private:
    Ui::MainWindow *ui;
    std::vector<HappinessReport> vec;
    ProxyModel *proxyModel;
    Model *_model;
    QList<QList<QString>> dataTable;
};
#endif  // MAINWINDOW_H
