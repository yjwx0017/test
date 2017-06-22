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
#include <QTableView>

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

	QGroupBox* setting = new QGroupBox(tr("Setting"));
	setting->setLayout(settingLayout);
	setting->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	QTableView* fileList = new QTableView;

	QLabel* total = new QLabel(tr("Total:"));
	QLabel* codes = new QLabel(tr("Codes:"));
	QLabel* comments = new QLabel(tr("Comments:"));
	QLabel* blankLines = new QLabel(tr("BLank Lines:"));

	QLineEdit* totalEdit = new QLineEdit;
	QLineEdit* codesEdit = new QLineEdit;
	QLineEdit* commentsEdit = new QLineEdit;
	QLineEdit* blankLinesEdit = new QLineEdit;

	QGridLayout* leftPart = new QGridLayout;
	leftPart->addWidget(total, 0, 0, 1, 1);
	leftPart->addWidget(totalEdit, 0, 1, 1, 1);
	leftPart->addWidget(comments, 1, 0, 1, 1);
	leftPart->addWidget(commentsEdit, 1, 1, 1, 1);

	QGridLayout* rightPart = new QGridLayout;
	rightPart->addWidget(codes, 0, 0, 1, 1);
	rightPart->addWidget(codesEdit, 0, 1, 1, 1);
	rightPart->addWidget(blankLines, 1, 0, 1, 1);
	rightPart->addWidget(blankLinesEdit, 1, 1, 1, 1);

	QHBoxLayout* allPart = new QHBoxLayout;
	allPart->addLayout(leftPart);
	allPart->addSpacing(10);
	allPart->addLayout(rightPart);

	QVBoxLayout* statisticsLayout = new QVBoxLayout;
	statisticsLayout->addWidget(fileList);
	statisticsLayout->addLayout(allPart);

	QGroupBox* statistics = new QGroupBox(tr("Statistics"));
	statistics->setLayout(statisticsLayout);

	QVBoxLayout* leftLayout = new QVBoxLayout;
	leftLayout->addWidget(setting);
	leftLayout->addWidget(statistics);

	QPushButton* start = new QPushButton(tr("Count"));
	QPushButton* stop = new QPushButton(tr("Stop"));
	QPushButton* output = new QPushButton(tr("Output"));
	QPushButton* about = new QPushButton(tr("About"));
	QPushButton* quit = new QPushButton(tr("Quit"));

	QVBoxLayout* rightLayout = new QVBoxLayout;
	rightLayout->addWidget(start);
	rightLayout->addWidget(stop);
	rightLayout->addWidget(output);
	rightLayout->addStretch();
	rightLayout->addWidget(about);
	rightLayout->addWidget(quit);

	QHBoxLayout* rootLayout = new QHBoxLayout(this);
	rootLayout->addLayout(leftLayout);
	rootLayout->addLayout(rightLayout);

	connect(start, SIGNAL(clicked(bool)), this, SLOT(onStartCount()));
	connect(stop, SIGNAL(clicked(bool)), this, SLOT(onStopCount()));
	connect(output, SIGNAL(clicked(bool)), this, SLOT(onOutputResult()));
	connect(about, SIGNAL(clicked(bool)), this, SLOT(onAbout()));
	connect(quit, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::onStartCount()
{

}

void MainWindow::onStopCount()
{

}

void MainWindow::onOutputResult()
{

}

void MainWindow::onAbout()
{

}

