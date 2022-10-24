#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent) : QSortFilterProxyModel(parent)
{
    happinessRank = 0;
    region = QString();
    country = QString();
}

void ProxyModel ::set_region(QString region)  // 2
{
    if (region.trimmed().isEmpty())
        this->region = QString();
    else
        this->region = region;
    invalidateFilter();
}

void ProxyModel ::set_country(QString country)  // 1
{
    if (country.trimmed().isEmpty())
        this->country = QString();
    else
        this->country = country;
    invalidateFilter();
}

void ProxyModel ::set_happinessRank(int happinessRank)  // 0
{
    this->happinessRank = happinessRank;
    invalidateFilter();
}

bool ProxyModel::filterAcceptsRow(int sourceRow,
                                  const QModelIndex& sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    int happinessRank = sourceModel()->data(index).toInt();

    QModelIndex country_index =
        sourceModel()->index(sourceRow, 1, sourceParent);
    QString country = sourceModel()->data(country_index).toString();

    QModelIndex region_index = sourceModel()->index(sourceRow, 2, sourceParent);
    QString region = sourceModel()->data(region_index).toString();
    if (this->region.trimmed().isEmpty() && this->happinessRank == 0 &&
        this->country.trimmed().isEmpty())
        return true;  // none
    if (this->region.trimmed().isEmpty() && this->happinessRank == 0)
        return this->country == country;  // only country
    if (this->country.trimmed().isEmpty() && this->happinessRank == 0)
        return this->region == region;  // only region
    if (this->region.trimmed().isEmpty() && this->country.trimmed().isEmpty())
        return this->happinessRank == happinessRank;  // only happiness rank
    if (this->happinessRank == 0)
        return this->country == country &&
               this->region == region;  // country region
    if (this->region.trimmed().isEmpty())
        return this->country == country &&
               this->happinessRank == happinessRank;  // country happ r
    if (this->country.trimmed().isEmpty())
        return this->region == region &&
               this->happinessRank == happinessRank;  // region happ r
    return this->country == country && this->region == region &&
           this->happinessRank == happinessRank;
}
