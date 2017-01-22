#include "mytreeviewmodel.h"

MyTreeViewModel::MyTreeViewModel(QObject* parent)
	: QAbstractItemModel(parent)
{

}

MyTreeViewModel::~MyTreeViewModel()
{

}

int MyTreeViewModel::rowCount(const QModelIndex &parent) const
{
	if (parent == QModelIndex())
		return 2;

	if (parent.row() == 1)
		return 1;

	return 0;
}

int MyTreeViewModel::columnCount(const QModelIndex &/*parent*/) const
{
	return 2;
}

QVariant MyTreeViewModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole)
		return QVariant("Test:)");

	return QVariant();
}

QModelIndex MyTreeViewModel::index(int row, int column, const QModelIndex &parent) const
{
	if (parent.row() == 1)
		return createIndex(row + 2, column);

	return createIndex(row, column);
}

QModelIndex MyTreeViewModel::parent(const QModelIndex &index) const
{

	return QModelIndex();
}

QVariant MyTreeViewModel::headerData(int section, Qt::Orientation orientation,
								int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (section == 0)
			return QVariant("Name");
		else if (section == 1)
			return QVariant("Value");
	}
	return QVariant();
}


