#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//QTranslator qtTranslator;
	//qtTranslator.load("qt_" + QLocale::system().name(),
	//				  QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	//app.installTranslator(&qtTranslator);


	MainWindow w;
	w.show();

	return a.exec();
}
