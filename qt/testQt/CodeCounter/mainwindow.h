#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public Q_SLOTS:
	void onStartCount();
	void onStopCount();
	void onOutputResult();
	void onAbout();
};

#endif // MAINWINDOW_H
