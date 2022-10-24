#ifndef ADDWIND_H
#define ADDWIND_H
#include <QDialog>
#include <QStandardItemModel>
#include <QStringListModel>

#include "HappinessReport.h"

namespace Ui
{
class AddWind;
}

class AddWind : public QDialog
{
    Q_OBJECT

   public:
    explicit AddWind(QWidget *parent = nullptr);
    ~AddWind();
    void setPointers(QStandardItemModel *model);

   private slots:
    void on_pushButton_clicked();

    // void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

   private:
    Ui::AddWind *ui;
    QStandardItemModel *model;
};

#endif  // ADDWIND_H
