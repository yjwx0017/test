#ifndef MYTREEVIEWMODEL_H
#define MYTREEVIEWMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QString>
#include <QStringList>

class MyTreeViewModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	MyTreeViewModel(QObject* parent);
	~MyTreeViewModel();

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	virtual QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
	virtual QVariant headerData(int section, Qt::Orientation orientation,
								int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;


private:
};

#endif // MYTREEVIEWMODEL_H
