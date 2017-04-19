#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QFileSystemModel>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	// Folder layout
	QLineEdit* edit = new QLineEdit;
	edit->setReadOnly(true);

	QPushButton* button = new QPushButton(tr("Open"));

	QHBoxLayout* folderLayout = new QHBoxLayout;
	folderLayout->addWidget(edit);
	folderLayout->addWidget(button);

	// File tree layout
	QFileSystemModel* fileSystemModel = new QFileSystemModel(this);

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
