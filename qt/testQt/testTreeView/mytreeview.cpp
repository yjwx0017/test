#include "mytreeview.h"
#include <QPainter>

MyTreeView::MyTreeView(QWidget* parent)
	: QTreeView(parent)
{

}

MyTreeView::~MyTreeView()
{

}

void MyTreeView::drawRow(QPainter *painter,
						 const QStyleOptionViewItem &options,
						 const QModelIndex &index) const
{
	QTreeView::drawRow(painter, options, index);
	//painter->drawRect(options.rect);

	//style()->drawItemText(painter, options.rect.adjusted(0, 0, -20, 0),
	//					  Qt::AlignLeft | Qt::TextDontClip, palette(), true, "Test just test,test,testtesttesttest");
}

void MyTreeView::drawBranches(QPainter *painter,
							  const QRect &rect,
							  const QModelIndex &index) const
{
	QTreeView::drawBranches(painter, rect, index);
	painter->save();
	painter->setPen(QColor(255, 0, 0));
	painter->drawRect(rect);
	painter->restore();
}
