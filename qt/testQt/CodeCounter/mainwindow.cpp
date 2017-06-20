#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QFileSystemModel>
#include <QDir>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
//	// Folder layout
//	QLineEdit* edit = new QLineEdit;
//	edit->setReadOnly(true);

//	QPushButton* button = new QPushButton(tr("Open"));

//	QHBoxLayout* folderLayout = new QHBoxLayout;
//	folderLayout->addWidget(edit);
//	folderLayout->addWidget(button);

//	// File tree layout
//	QFileSystemModel* fileSystemModel = new QFileSystemModel(this);

//	fileSystemModel->setRootPath(QDir::currentPath());

//	QTreeView* treeView = new QTreeView;
//	treeView->setAlternatingRowColors(true);
//	treeView->setModel(fileSystemModel);
//	treeView->setRootIndex(fileSystemModel->index(QDir::currentPath()));


//	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
//	verticalLayout->addLayout(folderLayout);
//	verticalLayout->addWidget(treeView);

	QLabel* fileTypeLabel = new QLabel(tr("File Type:"));
	QComboBox* fileTypeComboBox = new QComboBox;
	//initFileTypeComboBox(fileTypeComboBox);

	QLabel* dirLabel = new QLabel(tr("Source Dir:"));
	QComboBox* dirComboBox = new QComboBox;
	dirComboBox->setEditable(true);
	//initDirComboBox(dirComboBox);
	QPushButton* openButton = new QPushButton("Open...");
	openButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	QHBoxLayout* dirLayout = new QHBoxLayout;
	dirLayout->addWidget(dirComboBox);
	dirLayout->addWidget(openButton);

	QCheckBox* containSubDir = new QCheckBox("Contain Sub Dir(&R)");

	QGridLayout* settingLayout = new QGridLayout;
	settingLayout->setColumnStretch(0, 0);
	settingLayout->setColumnStretch(1, 1);
	settingLayout->addWidget(fileTypeLabel, 0, 0, 1, 1);
	settingLayout->addWidget(fileTypeComboBox, 0, 1, 1, 1);
	settingLayout->addWidget(dirLabel, 1, 0, 1, 1);
	settingLayout->addLayout(dirLayout, 1, 1, 1, 1);
	settingLayout->addWidget(containSubDir, 2, 1, 1, 1);

	QGroupBox* settingGroupBox = new QGroupBox(tr("Setting"));
	settingGroupBox->setLayout(settingLayout);
	settingGroupBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	QHBoxLayout* rootLayout = new QHBoxLayout(this);
	rootLayout->addWidget(settingGroupBox);

}

MainWindow::~MainWindow()
{

}
