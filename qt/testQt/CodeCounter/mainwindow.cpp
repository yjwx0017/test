#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	QLineEdit* edit = new QLineEdit;
	edit->setReadOnly(true);

	QPushButton* button = new QPushButton(tr("浏览"));

	QHBoxLayout* folderLayout = new QHBoxLayout;
	folderLayout->addWidget(edit);
	folderLayout->addWidget(button);


	QVBoxLayout* verticalLayout = new QVBoxLayout(this);
	verticalLayout->addLayout(folderLayout);
}

MainWindow::~MainWindow()
{

}
