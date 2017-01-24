#ifndef MYTREEVIEW_H
#define MYTREEVIEW_H

#include <QTreeView>


class MyTreeView : public QTreeView
{
	Q_OBJECT

public:
	MyTreeView(QWidget* parent);
	~MyTreeView();

protected:
	virtual void drawRow(QPainter *painter,
						 const QStyleOptionViewItem &options,
						 const QModelIndex &index) const Q_DECL_OVERRIDE;
	virtual void drawBranches(QPainter *painter,
							  const QRect &rect,
							  const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // MYTREEVIEW_H
