#include "mainwindow.h"
#include <QTreeView>
#include <QDebug>
#include "mytreeviewmodel.h"
#include "mytreeview.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	MyTreeView* treeView = new MyTreeView(this);
	setCentralWidget(treeView);

	if (!treeView->model())
		qDebug() << "model is null";

	treeView->setModel(new MyTreeViewModel(this));
}

MainWindow::~MainWindow()
{

}
