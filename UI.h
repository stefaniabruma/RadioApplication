#pragma once

#include "Service.h"
#include "MyTableModel.h"
#include <qwidget.h>
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qslider.h>
#include <qlabel.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qpainter.h>

class UserInterface : public QWidget
{
private:

	Service& serv;

	MyTableModel* model = new MyTableModel{ serv };
	QTableView* lista = new QTableView;

	QLineEdit* idTxt = new QLineEdit;
	QLineEdit* titluTxt = new QLineEdit;
	QSlider* sliderRank = new QSlider;

	QPushButton* modificaBtn = new QPushButton{ "&Modifica" };
	QPushButton* stergeBtn = new QPushButton{ "&Sterge" };
	QPushButton* undoBtn = new QPushButton{ "&Undo" };

	void setUp();
	void connectMethods();
public:

	UserInterface(Service& serv) : serv{ serv } { setUp(); connectMethods(); }
	void paintEvent(QPaintEvent* ev) override;
};