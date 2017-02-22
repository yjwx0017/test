#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QFileSystemModel>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	QLineEdit* edit = new QLineEdit;
	edit->setReadOnly(true);

	QPushButton* button = new QPushButton(tr("浏览"));

	QHBoxLayout* folderLayout = new QHBoxLayout;
	folderLayout->addWidget(edit);
	folderLayout->addWidget(button);

	QFileSystemModel* fileSystemModel = new QFileSystemModel(this);

	QDir path(".");
	path.makeAbsolute();

	fileSystemModel->setRootPath(QDir::currentPath());

	QTreeView* treeView = new QTreeView;
	treeView->setAlternatingRowColors(true);
	treeView->setModel(fileSystemModel);
	treeView->setRootIndex(fileSystemModel->index(QDir::currentPath()));


	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	verticalLayout->addLayout(folderLayout);
	verticalLayout->addWidget(treeView);
}

MainWindow::~MainWindow()
{

}
