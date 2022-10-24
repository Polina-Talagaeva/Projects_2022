#include "model.h"

Model::Model(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void Model::fillDataTableFromFile(const QString path)
{
    QFile inputFile(path);
    inputFile.open(QFile::ReadWrite | QFile::Text);
    QTextStream inputStream(&inputFile);

    QString firstline = inputStream.readLine();
    for (QString &item: firstline.split(","))
    {
        headerList.append(item);
    }

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        QList<QVariant> dataRow;

        for (QString &item: line.split(","))
        {
            bool integer = true;
            if (item.toInt(&integer))
            {
                dataRow.append(item.toInt());
            } else
            {
                dataRow.append(item);
            }
        }
        dataTable.append(dataRow);
    }
    inputFile.close();
}

int Model::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return dataTable.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    if (dataTable.empty())
    {
        return 0;
    }

    return dataTable[0].size();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        return headerList[section];
    }
    return QVariant();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        int row = index.row();
        int col = index.column();
        return dataTable[row][col];
    }
    return QVariant();
}

QVariant Model::getData(size_t row, size_t col) const
{
    return dataTable[row][col];
}

QList<QVariant> Model::getValues(size_t index)
{
    return {dataTable[index][1], dataTable[index][3]};
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        int row = index.row();
        int col = index.column();
        dataTable[row][col] = value.toString();
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
