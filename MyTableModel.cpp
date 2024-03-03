#include "MyTableModel.h"

int MyTableModel::rowCount(const QModelIndex& parent) const
{
	return serv.get_all_service().size();
}

int MyTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		Melodie mld = serv.get_all_service().at(index.row());

		if(index.column() == 0)
			return QString::fromStdString(std::to_string(mld.get_id()));

		if (index.column() == 1)
			return QString::fromStdString(mld.get_titlu());

		if (index.column() == 2)
			return QString::fromStdString(mld.get_artist());

		if (index.column() == 3)
			return QString::fromStdString(std::to_string(mld.get_rank()));

		if (index.column() == 4)
			return QString::fromStdString(std::to_string(serv.cate_cu_acelasi_rank(mld)));
	}

	return QVariant();
}
void MyTableModel::setMlds()
{
	auto topLeft = createIndex(0, 0);
	auto bottomRight = createIndex(rowCount(), columnCount());

	emit dataChanged(topLeft, bottomRight);
	emit layoutChanged();
}