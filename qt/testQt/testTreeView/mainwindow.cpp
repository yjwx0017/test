#include "mainwindow.h"
#include <QTreeView>
#include <QDebug>
#include "mytreeviewmodel.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	QTreeView* treeView = new QTreeView(this);
	setCentralWidget(treeView);

	if (!treeView->model())
		qDebug() << "model is null";

	treeView->setModel(new MyTreeViewModel(this));
}

MainWindow::~MainWindow()
{

}
