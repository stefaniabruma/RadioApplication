#pragma once
#include "Service.h"
#include <qtableview.h>

class MyTableModel : public QAbstractTableModel
{
private:
	Service& serv;

public:

	MyTableModel(Service& serv) :serv{ serv } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index = QModelIndex(), int role = Qt::DisplayRole) const override;

	void setMlds();
};