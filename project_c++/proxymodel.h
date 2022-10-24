#ifndef PROXYMODEL_H
#define PROXYMODEL_H
#include <QSortFilterProxyModel>
#include <QString>

class ProxyModel : public QSortFilterProxyModel
{
   public:
    ProxyModel(QObject* parent = 0);

    void set_happinessRank(int happinessRank);
    void set_region(QString region);
    void set_country(QString country);

    int get_happinessRank() const { return happinessRank; }
    QString get_region() const { return region; }
    QString get_country() const { return country; }

   protected:
    bool filterAcceptsRow(int sourceRow,
                          const QModelIndex& sourceParent) const override;

   private:
    QString region;
    QString country;
    int happinessRank;
};

#endif  // PROXYMODEL_H
